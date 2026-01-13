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

int waterTrapped(int arr[],int n){ // Prefix & Suffix Arrays (Better) T.C O(n). S.C O(n)
    int waterCap=0;
    int leftMax[n];int rightMax[n];
    leftMax[0]=arr[0];
    for(int i=1; i<n; i++){
        leftMax[i]= max(leftMax[i-1],arr[i]);  // storing leftMax for every index in array
    }
    rightMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],arr[i]); // storing rightMax for every index in array
    }
    for(int i=0; i<n; i++){
        waterCap += min(leftMax[i],rightMax[i])-arr[i];
    }
    return waterCap;
}
int main (){
    int arr[]={4,2,0,3,2,5};
    int n=6;
    cout<<waterStored(arr,n)<<endl;
}