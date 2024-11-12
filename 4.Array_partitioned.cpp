// Write a program that takes as input an array of numbers along an partition element from the array and returns a partition array corresponding to the element.

#include <iostream>
using namespace std;

void partition(int arr[], int n, int p, int result[]) {
    int l = 0;
    int g = n - 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < p) {
            result[l] = arr[i];
            l=l+1;
        } else if (arr[i] > p) {
            result[g] = arr[i];
            g=g-1;
        }
    }

    // Place the partition element in its correct position
    result[l] = p;

    // Print the partitioned array
    cout << "Partitioned Array: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {6, 2, 10, 5, 4, 11, 15, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int partitionElement = 6;
    int result[size];
    
    partition(arr, size, partitionElement, result);
    
    return 0;
}
// ********************************OUTPUT*****************************
//   Partitioned Array: 2 5 4 5 6 15 11 10
