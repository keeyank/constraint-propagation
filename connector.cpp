#include <vector>
#include <iostream>

#include "connector.h"
#include "constraint.h"

double Connector::val() const {
    if (!hasValue)
        throw std::runtime_error("Connector::val: "
            "Tried to access non-existant value");
    return value; 
}

void Connector::addConstraint(Constraint* c) {
    constraints.push_back(c);
}

void Connector::setVal(double val) {
    if (hasValue)
        throw std::runtime_error("Connector::setVal: "
            "Tried to set value when a value already exists");
    hasValue = true;
    value = val;
    notifyConstraints();
}

void Connector::forgetVal() {
    if (!hasValue)
        throw std::runtime_error("Connector::forgetVal: "
            "Tried to forget value when no value exist");
    hasValue = false;
    notifyConstraintsForget();
}

std::ostream &operator<<(std::ostream &os, const Connector &c) {
    return c.hasVal() ? os << c.val() : os << "?";
}