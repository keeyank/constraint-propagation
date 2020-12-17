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

    cout << equals << equals2 << a1 << a2;

    Connector m1prod, a2multyguy;
    MulterConstraint m1 {&m1prod, &a2sum, &a2multyguy};

    cout << endl << m1 << endl;

    m1prod.setVal(10);

    cout << equals << equals2 << a1 << a2 << m1 << endl;

    Connector hi1 {1}, hi2 {2}, hi3;
    AdderConstraint hi_there {&hi1, &hi2, &hi3};

    m1prod.forgetVal();

    cout << equals << equals2 << a1 << a2 << m1 << hi_there << endl;

    Connector constGuy {1, true};
    Connector nonconstGuy;
    cout << constGuy << nonconstGuy << endl;

    EqualsConstraint eqwalz {&constGuy, &nonconstGuy};
    cout << eqwalz;
    nonconstGuy.forgetVal();
    cout << eqwalz;
    // This is weird - we should make it so if all other connectors in a
    // guy is const, so is  CHECK NOTEBOOK.
    return 0;
}