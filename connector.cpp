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

void Connector::setVal(double val) {
    if (hasValue)
        throw std::runtime_error("Connector::setVal: "
            "Tried to set value when a value already exists");
    if (isCnst)
        throw std::runtime_error("Connector::setVal: "
            "Tried to set value on a const connector");
    hasValue = true;
    value = val;
    notifyConstraints();
}

void Connector::forgetVal() {
    if (!hasValue)
        throw std::runtime_error("Connector::forgetVal: "
            "Tried to forget value when no value exist");
    if (isCnst)
        throw std::runtime_error("Connector::forgetVal: "
            "Tried to forget value on a const connector");
    hasValue = false;
    notifyConstraintsForget();
}

void Connector::makeConst() {
    if (!hasValue)
        throw std::runtime_error("Connector::makeConst: "
            "Connector must have a value before being made const");
    if (isCnst)
        throw std::runtime_error("Connector::makeConst: "
            "Tried to make a connector const twice");
    isCnst = true; 
    notifyConstraintsConst();
}

void Connector::addConstraint(Constraint* c) {
    constraints.push_back(c);
}

std::ostream &operator<<(std::ostream &os, const Connector &c) {
    if (c.isConst()) 
        os << "(const) ";
    return c.hasVal() ? os << c.val() 
        : os << "?";
}