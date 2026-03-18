#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,8,5,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] >arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }

    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;



}