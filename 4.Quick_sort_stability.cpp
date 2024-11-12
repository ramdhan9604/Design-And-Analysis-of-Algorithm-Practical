#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

bool isStable(int original[], int sorted[], int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != sorted[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {6, 6, 6, 6, 4, 11, 15, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sorted[size];

    // Copy the original array into the sorted array for sorting
    for (int i = 0; i < size; i++) {
        sorted[i] = arr[i];
    }

    quickSort(sorted, 0, size - 1);

    if (isStable(arr, sorted, size)) {
        cout << "The quick sort is stable." << endl;
    } else {
        cout << "The quick sort is not stable." << endl;
    }

    return 0;
}


// *********************OUTPUT*****************
//   The quick sort is not stable.
