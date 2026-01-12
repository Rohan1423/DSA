#include <iostream>
using namespace std;

int waterStored(int arr[],int n){ // Brute Force Approach  T.C O(n x n)  S.C O(1)
    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        int leftMax=0;
        int rightMax=0;
        for(int j=0; j<=i; j++){
            leftMax=max(leftMax,arr[j]);
        }
        for(int j=i;j<n;j++){
            rightMax=max(rightMax,arr[j]);
        }
        waterTrapped += min(leftMax,rightMax)-arr[i];
    }
    return waterTrapped;
    
}
int main (){
    int arr[]={4,2,0,3,3,5};
    int n=6;
    cout<<waterStored(arr,n)<<endl;
}