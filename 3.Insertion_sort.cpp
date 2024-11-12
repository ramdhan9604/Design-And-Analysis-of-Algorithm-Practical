#include<iostream>

using namespace std;

void insertion_sort(int arr[],int size){
    int i,j,key;
    for(int i=1;i<size;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }
}

void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={6,2,10,5,4,11,15};
    int size= sizeof(arr)/sizeof(arr[0]);

    cout<<"The original array: ";
    print_array(arr,size);
    insertion_sort(arr,size);
    cout<<"\n The sorted array : ";
    print_array(arr,size);
    return 0;
}


// ********************OUTPUT***********************
// The original array: 6 2 10 5 4 11 15 
// The sorted array : 2 4 5 6 10 11 15
