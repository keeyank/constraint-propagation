#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "connector.h"

class Connector;

/*
Constraints hold multiple connectors, and define how to update
it's connectors whenever one of it's connectors gains a value.
*/
class Constraint {
    friend std::ostream& operator<<
        (std::ostream& os, const Constraint& c);

public:
    Constraint(const std::initializer_list<Connector*>& connectors);
    virtual void notify() = 0;
    void forgetCascade();
    
private:
    std::vector<Connector*> connectrs;
};
std::ostream& operator<<(std::ostream& os, const Constraint& c);

// c1 = c2;
class EqualsConstraint : public Constraint {
public:
    EqualsConstraint(Connector* connect1, Connector* connect2);

    void notify();
private:
    Connector *c1, *c2;
};

// c1 = c2 + c3;
class AdderConstraint : public Constraint {
public:
    AdderConstraint(Connector* cn1, Connector* cn2, Connector* c3);
    void notify();
private:
    Connector *c1, *c2, *c3;
};

// c1 = c2 * c3;
class MulterConstraint : public Constraint {
public:
    MulterConstraint(Connector* cn1, Connector* cn2, Connector* c3);
    void notify();
private:
    Connector *c1, *c2, *c3;
};

#endif