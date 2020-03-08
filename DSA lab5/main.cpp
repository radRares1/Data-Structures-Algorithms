#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
    testAll();
    cout << "Simple test passed\n";
    //Simple test

    testAllExtended();
    cout << "Extended test passed\n";
    //Extended test

    cout << "End\n";
}