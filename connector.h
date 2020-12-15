#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <iostream>

#include "constraint.h"

class Constraint;

// Connectors hold values, which are attached to constraints.
// Corresponds to symbols within a mathematical equations.
class Connector {
public:
    Connector() = default;
    Connector(double val)
        : hasValue{true}, value{val} { }

    bool hasVal() const { return hasValue; }
    double val() const { return value; }

    void setVal(double val);

    void addConstraint(Constraint* c);

private:
    void notifyConstraints() {
        for (Constraint *c : constraints)
            c->notify();
    }

    bool hasValue = false;
    double value = 0.;
    std::vector<Constraint*> constraints;
};

std::ostream &operator<<(std::ostream &os, const Connector &c);

#endif