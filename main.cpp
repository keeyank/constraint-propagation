#include <iostream>

#include "connector.h"
#include "constraint.h"

using namespace std;

int main() {
    Connector eq1 {2}, 
        a1sum {2}, a1summand1, a1summand2,
        a2sum, a2summand1, a2summand2;


    EqualsConstraint equals {&eq1, &a1sum};
    AdderConstraint a1 {&a1sum, &a1summand1, &a1summand2};

    cout << equals << a1;

    a1summand1.setVal(1);

    cout << equals << a1;

    AdderConstraint a2 {&a2sum, &a2summand1, &a2summand2};
    EqualsConstraint equals2 {&eq1, &a2summand1};

    cout << equals << equals2 << a1 << a2;

    a2summand2.setVal(3);

    cout << 

    return 0;
}