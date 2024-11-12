#include <iostream>
using namespace std;

// Dynamic Programming with Bottom-Up Approach using Array
int fibonacciBottomUp(int n) {
    if (n <= 1)
        return n;

    int fib[n + 1]; // Array to store Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci number (Bottom-Up) for " << n << " is: " << fibonacciBottomUp(n) << endl;
    return 0;
}


// *************************OUTPUT*************************
// Fibonacci number (Bottom-Up) for 10 is: 55
