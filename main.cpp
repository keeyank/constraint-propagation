#include <iostream>

#include "connector.h"
#include "constraint.h"

using namespace std;

int main() {
    Connector c1 {3.2};
    Connector c2;

    Constraint equals {&c1, &c2};

    cout << c1 << ' ' << c2 << endl;;
    return 0;
}