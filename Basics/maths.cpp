#include<iostream>
using namespace std;

int main(){
    int num1 ;
    int num2;
    cout<<"Enter 1st number: ";
    cin>>num1;

    cout<<"Enter 2nd number: ";
    cin>>num2;


    int add = num1+num2;
    int sub = num1 - num2;
    int mul = num1*num2;
    int div = num2/num1;

    cout<<"addition:"<<add<<endl;
    cout<<"subtraction:"<<sub<<endl;
    cout<<"multipication:"<<mul<<endl;
    cout<<"division:"<<div<<endl;

}