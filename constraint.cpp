#include "connector.h"
#include "constraint.h"

/* Utility functions */

bool inline closeEnough(int a, int b) {
    static constexpr double accuracy {.01};
    return abs(a - b) < accuracy;
}

/* Constraint generic interface */

/*
If a connector is determined to be const (which occurs when all other
connectors except it are const), return a pointer to that connector.
Else, return nullptr.
*/
Connector* Constraint::getConstDetermined() {
    unsigned constCount {0};
    Connector *nonConst;
    for (Connector *c : connectrs) {
        if (c->isConst()) ++constCount;
        else nonConst = c;
    }

    if (constCount == connectrs.size() - 1)
        return nonConst;
    else return nullptr;
}

Constraint::Constraint(const std::initializer_list<Connector*> &connectors) 
    : connectrs{connectors.begin(), connectors.end()} 
{ 
    for (Connector *c : connectors)
        c->addConstraint(this);
}

void Constraint::notifyConst() {
    Connector* determined = getConstDetermined();
    if (determined)
        determined->makeConst();
}

void Constraint::notifyForget() {
    for (Connector *c : connectrs) {
        if (c->hasVal() && !c->isConst())
            c->forgetVal();
    }
}

std::ostream& operator<<(std::ostream& os, const Constraint& c) {
    for (Connector *c : c.connectrs)
        os << *c << ',';
    return os << '\b' << std::endl;
}

/* EqualsConstraint */

EqualsConstraint::EqualsConstraint
(Connector *connect1, Connector *connect2) 
    : Constraint{{connect1, connect2}}, c1{connect1}, c2{connect2}
{
    notifyVal();
    notifyConst();
}

void EqualsConstraint::notifyVal() {
    if (c1->hasVal() && c2->hasVal()) {
        if (!closeEnough(c1->val(), c2->val()))
            throw std::runtime_error(
                "EqualsConstraint::EqualsConstraint: "
                "Contradiction");
    }
    else {
        if (c1->hasVal())
            c2->setVal(c1->val());
        else if (c2->hasVal())
            c1->setVal(c2->val());
    }
}

/* AdderConstraint */

AdderConstraint::AdderConstraint
(Connector* cn1, Connector* cn2, Connector* cn3)
    : Constraint{{cn1, cn2, cn3}}, c1{cn1}, c2{cn2}, c3{cn3}
{
    notifyVal();
    notifyConst();
}

void AdderConstraint::notifyVal() {
    if (c1->hasVal() && c2->hasVal() && c3->hasVal()) {
        if (!closeEnough(c1->val(), c2->val() + c3->val()))
            throw std::runtime_error(
                "AdderConstraint::AdderConstraint: "
                "Contradiction");
    }
    else {
        if (c1->hasVal() && c2->hasVal())
            c3->setVal(c1->val() - c2->val());
        else if (c1->hasVal() && c3->hasVal())
            c2->setVal(c1->val() - c3->val());
        else if (c2->hasVal() && c3->hasVal())
            c1->setVal(c2->val() + c3->val());
    }
}

/* MulterConstraint */

MulterConstraint::MulterConstraint
(Connector* cn1, Connector* cn2, Connector* cn3)
    : Constraint{{cn1, cn2, cn3}}, c1{cn1}, c2{cn2}, c3{cn3}
{
    notifyVal();
    notifyConst();
}

void MulterConstraint::notifyVal() {
    if (c1->hasVal() && c2->hasVal() && c3->hasVal()) {
        if (!closeEnough(c1->val(), c2->val() * c3->val()))
            throw std::runtime_error(
                "MulterConstraint::MulterConstraint: "
                "Contradiction");
    }
    else {
        if (c1->hasVal() && c2->hasVal())
            c3->setVal(c1->val() / c2->val());
        else if (c1->hasVal() && c3->hasVal())
            c2->setVal(c1->val() / c3->val());
        else if (c2->hasVal() && c3->hasVal())
            c1->setVal(c2->val() * c3->val());
    }
}