#include <iostream>
using namespace std;

int maxProdSubArr(int arr[],int n){ // Brute Force T.C O(n x n) S.C O(1)
    int maxProd=arr[0];
    for(int i=0; i<n; i++){
        int prod=1;
        for(int j =i; j<n; j++){
            prod *= arr[j];
            maxProd=max(maxProd,prod);
        }
    }
    return maxProd;
}

int maximumProductSubArray(int arr[], int n) {  // Optimal Approach (Kadane-style for Product) T.C O(n) S.C O(1)

    // maxProd → maximum product ending at current index
    // minProd → minimum product ending at current index
    // (needed because a negative number can turn min into max)
    int maxProd = arr[0];
    int minProd = arr[0];

    // Stores the final maximum product found so far
    int result = arr[0];

    for (int i = 1; i < n; i++) {

        // If current element is negative,
        // multiplying will flip signs → swap max & min
        if (arr[i] < 0) {
            swap(maxProd, minProd);
        }

        // Either:
        // start new subarray from current element
        // extend previous subarray
        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);

        // Update the global maximum product
        result = max(result, maxProd);
    }

    return result;
}


int main(){
    int arr[]={1,-2,3,4};
    cout<<maximumProductSubArray(arr,4);
}