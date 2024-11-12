#include<iostream>
using namespace std;

int power_4(int n) {
    if (n == 1) {
        return 1; // Base case: if n is reduced to 1, it’s a power of 4
    }
    if (n < 4 || n % 4 != 0) {
        return 0; // If n is less than 4 or not divisible by 4, it’s not a power of 4
    }
    else {
        return power_4(n / 4); // Recursive call, dividing n by 4
    }
}

int main() {
    int number;

    cout << "Enter the number: ";
    cin >> number;

    if (power_4(number) == 1) {
        cout << "Yes, it is a power of 4.";
    }
    else {
        cout << "No, it is not a power of 4.";
    }

    return 0;
}

// ******************OUTPUT*****************
// Enter the number: 4
// Yes, it is a power of 4.
