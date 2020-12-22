#include <iostream>

#include "connector.h"
#include "constraint.h"

using namespace std;

int main() {
    
    // Connector eq1 {2}, 
    //     a1sum, a1summand1, a1summand2,
    //     a2sum, a2summand1, a2summand2;

    // EqualsConstraint equals {&eq1, &a1sum};
    // AdderConstraint a1 {&a1sum, &a1summand1, &a1summand2};

    // cout << equals << a1;

    // a1sum.makeConst();

    // cout << equals << a1;

    // a1summand1.setVal(10);

    // cout << equals << a1 << endl;

    // a1summand2.forgetVal();

    // cout << equals << a1 << endl;

    // a1summand1.setVal(1);

    // cout << equals << a1 << endl;

    // a1summand2.makeConst();

    // cout << equals << a1 << endl;

    // AdderConstraint a2 {&a2sum, &a2summand1, &a2summand2};
    // EqualsConstraint equals2 {&eq1, &a2summand1};

    // cout << equals << equals2 << a1 << a2;

    // a2summand2.setVal(3);

    // cout << equals << equals2 << a1 << a2;

    // a2sum.forgetVal();

    // cout << equals << equals2 << a1 << a2 << endl;

    // a2summand2.setVal(3);

    // cout << a2 << endl;

    // Connector m1prod, a2multyguy;
    // MulterConstraint m1 {&m1prod, &a2sum, &a2multyguy};

    // cout << endl << m1 << endl;

    // m1prod.setVal(10);

    // cout << equals << equals2 << a1 << a2 << m1 << endl;

    // Connector hi1 {1}, hi2 {2}, hi3;
    // AdderConstraint hi_there {&hi1, &hi2, &hi3};

    // m1prod.forgetVal();

    // cout << equals << equals2 << a1 << a2 << m1 << hi_there << endl;

    // Connector constGuy {1, true};
    // Connector nonconstGuy;
    // cout << constGuy << nonconstGuy << endl;

    // EqualsConstraint eqwalz {&constGuy, &nonconstGuy};
    // cout << eqwalz;
    // nonconstGuy.forgetVal();
    // cout << eqwalz;

    // Connector mr, blister, wristhurt;
    // MulterConstraint yaddup {&mr, &blister, &wristhurt};
    // mr.setVal(.5);
    // mr.makeConst();
    // blister.setVal(2);

    // cout << yaddup;

    // blister.forgetVal();
    // cout << yaddup;
    // wristhurt.setVal(.1);
    // cout << yaddup;
    

    /*
    // Bigquation
    Connector c, f,
        a {9, true}, b {5}, d {32, true},
        u, v;

    MulterConstraint mul1 {&u, &c, &a}, mul2 {&u, &v, &b};
    AdderConstraint add {&f, &v, &d};

    cout << c << f << endl << a << b << d << endl << u << v << endl;

    c.setVal(10);

    cout << c << f << endl << a << b << d << endl << u << v << endl;

    f.forgetVal();
    f.setVal(10.21);

    cout << c << f << endl << a << b << d << endl << u << v << endl;

    c.setVal(-12.1056);

    cout << c << f << endl << a << b << d << endl << u << v << endl;

    c.makeConst();

    cout << c << f << endl << a << b << d << endl << u << v << endl;

    b.makeConst();
    cout << c << f << endl << a << b << d << endl << u << v << endl;

    */
/*
    Connector mprod, mmult1, mmult2,
        a1sum, a1sum1 {2, true},
        a2sum, a2sum1,
        eqC;

    MulterConstraint m {&mprod, &mmult1, &mmult2};
    AdderConstraint a1 {&a1sum, &a1sum1, &mprod};
    AdderConstraint a2 {&a2sum, &a2sum1, &a1sum};
    EqualsConstraint eq {&eqC, &a2sum};

    mmult1.setVal(3);
    a1sum.setVal(11);

    cout << m << a1 << a2 << eq << endl;

    //mprod.makeConst();

    cout << m << a1 << a2 << eq << endl;

    mmult1.forgetVal();

    cout << m << a1 << a2 << eq << endl;

    eqC.setVal(15);
    //eqC.makeConst();

    cout << m << a1 << a2 << eq << endl;

    mprod.setVal(9);
    mmult1.setVal(3);
    mmult1.makeConst();

    cout << m << a1 << a2 << eq << endl;

    a2sum.makeConst();

    cout << m << a1 << a2 << eq << endl;

    //a1sum.forgetVal();
    a2sum1.makeConst();
cout << m << a1 << a2 << eq << endl;

*/

    return 0;
}