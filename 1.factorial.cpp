#include <iostream>
using namespace std;

int fact(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int n, result;

    cout << "Enter the number: ";
    cin >> n;

    result = fact(n);
    cout << "The factorial of " << n << " is: " << result;

    return 0;
}

********************OUTPUT*************************

// Enter the number: 5
// The factorial of 5 is: 120
