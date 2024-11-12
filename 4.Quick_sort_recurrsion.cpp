#include<iostream>

using namespace std;

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Use the first element as the pivot
    int i = low + 1;
    int j = high;
    int temp;

    // Change `if` to `while` to continue partitioning until `i > j`
    while (i <= j) {
        // Increment `i` until an element greater than the pivot is found
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        // Decrement `j` until an element less than the pivot is found
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        // Swap elements at `i` and `j` if `i` is still less than `j`
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot in its correct position
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;  // Return the partition index
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = Partition(arr, low, high);

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {6, 2, 10, 5, 4, 11, 15, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = size - 1;

    quick_sort(arr, low, high);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// **************************OUTPUT*******************
  // The sorted array is: 2 4 5 5 6 10 11 15 
