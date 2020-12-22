#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <iostream>

#include "constraint.h"

class Constraint;

/*
Connectors hold values, which are attached to constraints.
Corresponds to symbols within a mathematical equations.
Class invariant: Const connectors will always have a value.
*/
class Connector {
public:
    Connector() = default;
    Connector(double val, bool isConst = false)
        : hasValue{true}, isCnst{isConst}, value{val} { }

    bool hasVal() const { return hasValue; }
    double val() const;

    void setVal(double val);
    void forgetVal();

    bool isConst() const { return isCnst; }
    void makeConst();

    void addConstraint(Constraint* c);

private:
    void notifyConstraints() {
        for (Constraint *c : constraints)
            c->notifyVal();
    }

    void notifyConstraintsForget() {
        for (Constraint *c : constraints)
            c->notifyForget();
    }

    void notifyConstraintsConst() {
        for (Constraint *c : constraints)
            c->notifyConst();
    }

    bool hasValue = false, isCnst = false;
    double value = 0.;
    std::vector<Constraint*> constraints;
};

std::ostream &operator<<(std::ostream &os, const Connector &c);

#endif