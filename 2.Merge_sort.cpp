#include<iostream>

using namespace std;

void merged(int arr1[],int size1,int arr2[],int size2,int merged_arr[]){
    int i=0;
    int j=0;
    int k=0;

    while(i<size1 && j<size2){
        if(arr1[i]<=arr2[j]){
            merged_arr[k]=arr1[i];
            i++;
        }
        else{
            merged_arr[k]=arr2[j];
            j++;
        }
        k++;


    }
    while(i<size1){
        merged_arr[k]=arr1[i];
        i++;
        k++;

    }
    while(j<size2){
        merged_arr[k]=arr2[j];
        j++;
        k++;
    }
}

void merged_print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr1[]={1,2,3,4,5};
    int arr2[]={6,7,8,9};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2= sizeof(arr2)/sizeof(arr2[0]);

    int merged_arr[size1+size2];

    merged(arr1,size1,arr2,size2,merged_arr);

    merged_print(merged_arr,size1+size2);

    return 0;



}

// ********************OUTPUT*******************
//   1 2 3 4 5 6 7 8 9
