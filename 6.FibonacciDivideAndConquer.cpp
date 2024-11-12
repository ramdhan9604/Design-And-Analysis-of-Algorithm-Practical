#include <iostream>
using namespace std;

// Divide and Conquer approach
int fibonacciDivideAndConquer(int n) {
    if (n <= 1)
        return n;
    return fibonacciDivideAndConquer(n - 1) + fibonacciDivideAndConquer(n - 2);
}

int main() {
    int n = 10;
    cout << "Fibonacci number (Divide and Conquer) for " << n << " is: " << fibonacciDivideAndConquer(n) << endl;
    return 0;
}


// ********************OUTPUT*******************
// Fibonacci number (Divide and Conquer) for 10 is: 55
