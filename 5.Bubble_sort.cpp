#include<iostream>
using namespace std;

// Swap function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void bubble_sort(int arr[], int size) {
    int count = 0; // Counter for comparisons
    

    // Outer loop: Loop through the entire array
    for (int i = 0; i < size - 1; i++) {

        // Inner loop: Perform comparisons and swaps
        for (int j = 0; j < size - i - 1; j++) {
            count++;  // Count each comparison
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                
            }
        }
        
    }

    // Output the number of comparisons
    cout << "The number of comparisons: " << count << endl;
}

int main() {
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Call the optimized bubble sort
    bubble_sort(arr, size);

    // Output the sorted array
    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// ****************OUTPUT***************
// The number of comparisons: 28
// The sorted array is: 1 2 3 4 6 7 8 9


