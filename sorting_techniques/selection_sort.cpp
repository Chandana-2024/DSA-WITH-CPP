#include<bits/stdc++.h>
using  namespace std;

int main(){
    int arr[] = {2,8,3,6,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);


    for(int i=0;i<n-1;i++){
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[idx]){
                idx = j;
            }
        }
        swap(arr[i],arr[idx]);
    }


    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}