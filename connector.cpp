#include <vector>
#include <iostream>

#include "connector.h"
#include "constraint.h"

void Connector::addConstraint(Constraint* c) {
    constraints.push_back(c);
}

void Connector::setVal(double val) {
    if (hasValue)
        throw std::runtime_error("Connector::setVal: "
            "Tried to set value when a value already exists.");
    hasValue = true;
    value = val;

    notifyConstraints();
}

std::ostream &operator<<(std::ostream &os, const Connector &c) {
    return c.hasVal() ? os << c.val() : os << "?";
}