#include <iostream>
using namespace std;

void slidingWindowMax(int arr[],int n,int k){  // Brute Force  TC: O(n * k), SC: O(1)
    for(int i=0; i<=n-k;i++){
        int maximum=arr[i];
        for(int j=i;j<i+k;j++){
            maximum=max(maximum,arr[j]);
        }
        cout << maximum << " ";
    }
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8;
    int k = 3;
    slidingWindowMax(arr,n,k);
}