//23-02-26
#include<iostream>
using namespace std;

int main(){
    cout<<"enter a number:";
    int num1;
    cin>>num1;

    if(num1%2==0){
        cout<<num1<<" is a even number"<<endl;
    }else{
        cout<<num1<<" is a odd number "<<endl;
    }

    return 0;
}