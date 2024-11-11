// Ques1- Write a program to give sum of the first n natural numbers.

#include<iostream>

using namespace std;

int main(){

    int number;
    cout<<"Enter the number: ";
    cin>>number;

    int sum=0;
    for(int i=1;i<=number;i++){
        sum+=i;
    }

    cout<<"The sum of "<<number<<" natural number is: "<<sum;
    
    return 0;
}

// ***************OUTPUT*****************
// Enter the number: 10
// The sum of 10 natural number is: 55
