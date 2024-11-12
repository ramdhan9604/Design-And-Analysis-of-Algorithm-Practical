#include <iostream>
using namespace std;

int reverseNumber(int n, int reversed = 0) {
    if (n == 0) {
        return reversed;
    } else {
        reversed = (reversed * 10) + (n % 10);
        return reverseNumber(n / 10, reversed);
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int reversed = reverseNumber(number);
    cout << "Reversed number: " << reversed << endl;

    return 0;
}


// *************************OUTPUT******************
// Enter a number: 12345
// Reversed number: 54321
