#include <iostream>
using namespace std;

void DtoB(int n) {
    if (n == 0) {
        return;
    } else {
        DtoB(n / 2);
        cout << n % 2;
    }
}

int main() {
    int D;

    cout << "Enter a decimal number: ";
    cin >> D;

    if (D == 0) {
        cout << "0";
    } else {
        cout << "Binary representation of " << D << " is: ";
        DtoB(D);
    }
    cout << endl;

    return 0;
}
// *************************OUTPUT*******************

// Enter a decimal number: 35
// Binary representation of 35 is: 100011
