//23-02-206
#include<iostream>
using namespace std;

int main(){
    int n1;
    cout<<"Enter a number: ";
    cin>>n1;
    int n2;
    cout<<"Enter another number: ";
    cin>>n2;

    if(n1>n2){
        cout<<n1<<" is greater than "<<n2<<endl;
    }else{
        cout<<n2<<" is greater than "<<n1<<endl;
    }

    return 0;
}


