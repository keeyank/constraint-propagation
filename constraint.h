#ifndef CONSTRAINT_H
#define CONSTRAINT_H

class Constraint; // since connector.h uses Constraint

#include "connector.h"

/*
Constraints hold multiple connectors, and define how to update
it's connectors whenever one of it's connectors gains a value.
*/
// Equality constraint
class Constraint {
public:
    Constraint(Connector* connect1, Connector* connect2);

    void notify();
private:
    Connector* c1;
    Connector* c2;
};

#endif