//24/02/26
#include<iostream>
using namespace std;        

int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    int fact = 1;
    while(n>0){
        fact = fact * n;
        cout<<n<<" ";
        n--;
    }
    cout<<"Factorial is: "<<fact<<endl;
}