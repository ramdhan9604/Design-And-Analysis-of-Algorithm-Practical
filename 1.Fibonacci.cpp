#include<iostream>

using namespace std;

int main(){
    int a=0,b=1,c;
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    cout<<a<<endl;
    cout<<b<<endl;
    for(int i=3;i<=number;i++){
        int c=a+b;
        cout<<c;
        cout<<endl;
        a=b;
        b=c;
    }
    return 0;
}

// *******************OUTPUT******************

// Enter the number: 10
// 0
// 1
// 1
// 2
// 3
// 5
// 8
// 13
// 21
// 34
