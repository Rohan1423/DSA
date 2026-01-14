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

int waterTrapped(int arr[],int n){ // Prefix & Suffix Arrays (Better) T.C O(n). S.C O(n) Precompute: leftMax[i] & rightMax[i]
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

int waterCollected(int height[], int n) { // Two Pointer (Optimal) T.C O(n) O(1)

    // Left pointer starts from beginning of array
    int left = 0;

    // Right pointer starts from end of array
    int right = n - 1;

    // Stores maximum height seen so far from left side
    int leftMax = 0;

    // Stores maximum height seen so far from right side
    int rightMax = 0;

    // Total water trapped
    int water = 0;

    // Continue until both pointers meet
    while (left < right) {

        // Always process the smaller height
        // Water depends on the smaller boundary
        if (height[left] <= height[right]) {

            // If current bar is higher than leftMax
            // Update leftMax (no water trapped)
            if (height[left] > leftMax) {
                leftMax = height[left];
            }
            // Else water can be trapped above this bar
            else {
                water += leftMax - height[left];
            }

            // Move left pointer forward
            left++;
        }
        else {

            // If current bar is higher than rightMax
            // Update rightMax (no water trapped)
            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            // Else water can be trapped above this bar
            else {
                water += rightMax - height[right];
            }

            // Move right pointer backward
            right--;
        }
    }

    // Return total trapped water
    return water;
}
int main (){
    int arr[]={4,2,0,3,2,5};
    int n=6;
    cout<<waterCollected(arr,n)<<endl;
}