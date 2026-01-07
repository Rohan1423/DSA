#include <iostream>
using namespace std;

int maxSumOfContiguousSubArray(int arr[],int n){ // Brute Force Maximum Subarray Sum T.C O(n²) S.C O(1)
    int maxSum= INT_MIN;  // (-2,147,483,648) As,Array can contain all negative numbers
    for(int i=0; i<n; i++){
        int sum = 0;  // reset sum
        for(int j=i; j<n; j++){
           sum += arr[j];
           maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int maximumSumOfContiguousSubArray(int arr[], int n){  // Optimal Kadane’s Algorithm (At each element, you have two choices:Extend the previous subarray ==> Start fresh from the current element ==> If the previous sum becomes negative, discard it.)
    int currentSum = arr[0];
    int maxSum = arr[0];      // T.C O(n)  S.C O(1)
    for(int i=1; i<n; i++){
        currentSum= max(arr[i],currentSum+arr[i]); // Should I start a new subarray from here? OR should I extend the previous subarray?
        maxSum= max(maxSum,currentSum); // compare last maxSum and currentSum
    }
    return maxSum;
}

int maxSubArray(int arr[], int n) {  // Kadane rewritten as Sliding Window thinking  T.C O(n)  S.C O(1)
    int maxSum = arr[0];
    int windowSum = 0;

    for (int end = 0; end < n; end++) {
        windowSum += arr[end];

        maxSum = max(maxSum, windowSum);

        if (windowSum < 0) {
            windowSum = 0; // shrink window completely
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum = " << maxSubArray(arr, n);
    return 0;
}