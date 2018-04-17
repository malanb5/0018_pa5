#include <iostream>
using namespace std;

int main() {
    int val1 = 4;
    int val2 = 5;

    /**
     * Allocates two points
     */
    int * p1;
    int * p2;

    /**
     * p1 is assigned to the address of val1 which is a place in memory that stores the value 4.
     * p2 is assigned to p1, which makes a copy of the address.
     */

    p1 = & val1;
    p2 = p1;

    p1 = & val2;

    cout << * p1 << endl;
    cout << * p2 << endl;

    return 0;
}