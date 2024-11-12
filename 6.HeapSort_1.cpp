#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;        // Left child index
    int right = 2 * i + 2;       // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root, swap and recursively heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);        // Move current root to the end
        heapify(arr, i, 0);          // Heapify the reduced heap
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    int arr[20];
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapsort(arr, n);

    cout << "Sorted array is: " << endl;
    printArray(arr, n);

    return 0;
}

// *******************************OUTPUT*******************************
// Enter the number of elements in the array: 5
// Enter the elements:
// 25
// 58
// 36
// 69
// 14
// Sorted array is:
// 14 25 36 58 69
