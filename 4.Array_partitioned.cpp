// Write a program that takes as input an array of numbers along an partition element from the array and returns a partition array corresponding to the element.

#include <iostream>
using namespace std;

void partition(int arr[], int low, int high) {
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;

    while(i<=j){
        while(i<=high && arr[i]<=pivot){
            i=i+1;
        }
        while(j>=low && arr[j]>=pivot){
            j=j-1;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    }

    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    cout<<"The partioned array with pivot element index "<<j<< " is: ";
    for(int i=0;i<=high;i++){
        cout<<arr[i]<<" ";
    }
}
    
   
int main() {
    int arr[] = {6, 2, 10, 5, 4, 11, 15, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low=0;
    int high=size-1;
    
    partition(arr, low, high);
    
    return 0;
}

// ********************************OUTPUT*****************************
//   Partitioned Array: 2 5 4 5 6 15 11 10
