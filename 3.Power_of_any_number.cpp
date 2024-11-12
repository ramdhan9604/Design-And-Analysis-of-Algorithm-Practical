#include <iostream>
using namespace std;

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Base case: any number to the power of 0 is 1
    } else {
        return base * power(base, exponent - 1); // Recursive case
    }
}

int main() {
    int base, exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    int result = power(base, exponent);
    cout << base << " raised to the power " << exponent << " is: " << result << endl;

    return 0;
}


// ***********************OUTPUT*********************

// Enter the base: 5
// Enter the exponent: 3
// 5 raised to the power 3 is: 125
