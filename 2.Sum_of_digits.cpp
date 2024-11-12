#include<iostream>

using namespace std;

int sum_digits(int n){
    if(n==0){
        return 0;
    }
    else{
        return n%10 + sum_digits(n/10);
    }
}

int main(){
    int number;
    cout<<"Enter the number: ";
    cin>>number;

    cout<<"The sum of digits is: "<<sum_digits(number);

    return 0;
}


// ********************OUTPUT************************
// Enter the number: 12345
// The sum of digits is: 15
