#include "connector.h"
#include "constraint.h"

/* Constraint generic interface */

Constraint::Constraint(const std::initializer_list<Connector*> &connectors) 
    : connectrs{connectors.begin(), connectors.end()} 
{ 
    for (Connector *c : connectors)
        c->addConstraint(this);
}

void Constraint::forgetCascade() {
    for (Connector *c : connectrs) {
        if (c->hasVal() /* and c is non-const */)
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
    notify();
}

void EqualsConstraint::notify() {
    if (c1->hasVal() && c2->hasVal()) {
        if (c1->val() != c2->val())
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
    notify();
}

void AdderConstraint::notify() {
    if (c1->hasVal() && c2->hasVal() && c3->hasVal()) {
        if (c1->val() != c2->val() + c3->val())
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

MulterConstraint::MulterConstraint
(Connector* cn1, Connector* cn2, Connector* cn3)
    : Constraint{{cn1, cn2, cn3}}, c1{cn1}, c2{cn2}, c3{cn3}
{
    notify();
}

void MulterConstraint::notify() {
    if (c1->hasVal() && c2->hasVal() && c3->hasVal()) {
        if (c1->val() != c2->val() * c3->val())
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