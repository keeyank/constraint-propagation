#include "connector.h"
#include "constraint.h"

Constraint::Constraint(Connector *connect1, Connector *connect2) 
    : c1{connect1}, c2{connect2}
{
    c1->addConstraint(this);
    c2->addConstraint(this);
    notify();
}

void Constraint::notify() {
    if (c1->hasVal() && c2->hasVal()) {
        if (c1->val() != c2->val())
            throw std::runtime_error("Constraint::Constraint: "
                "Contradiction - c1 and c2 do not match");
        else return;
    }
    
    if (c1->hasVal())
        c2->setVal(c1->val());
    else if (c2->hasVal())
        c1->setVal(c2->val());
}