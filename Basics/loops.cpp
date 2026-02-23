//24-02-26
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            cout<<i<<" is a even number "<<endl;
        }else{
            cout<<i<<" is a odd number "<<endl;
        }
    }
}