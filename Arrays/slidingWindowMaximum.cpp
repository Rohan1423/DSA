#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Given an array arr[] and an integer k,find the maximum element in every contiguous subarray (window) of size k ?

void slidingWindowMax(int arr[],int n,int k){  // Brute Force  TC: O(n * k), SC: O(1)
    for(int i=0; i<=n-k;i++){
        int maximum=arr[i];
        for(int j=i;j<i+k;j++){
            maximum=max(maximum,arr[j]);
        }
        cout << maximum << " ";
    }
}

vector<int> slidingWindowMaxUsingDeque(vector<int>& arr, int n, int k) {  // Optimal Approach (Using Deque) T.C O(n). S.C O(k)

    deque<int> dq;     // stores indices
    vector<int> res;   // stores result

    // Process first window of size k
    for (int i = 0; i < k; i++) {

        // Remove elements from back if they are smaller than current element
        // They can NEVER be maximum in current or future windows
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Push current index at back
        dq.push_back(i);
    }

    // Front of deque has index of maximum element for first window
    res.push_back(arr[dq.front()]); // First window (0 to k-1) becomes complete only once,
                                    // so we push/print its maximum AFTER building it.

    // Process remaining windows
    for (int i = k; i < n; i++) {

        /*
        IMPORTANT:
        We store INDICES, not values.
        So we can check if an element is OUT of current window using:
            dq.front() <= i - k

        If index <= i - k:
        → element lies outside current window
        → remove it from front
        */
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all smaller elements from back
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Push current index
        dq.push_back(i);

        // Front of deque is MAX element of current window
        res.push_back(arr[dq.front()]);  // Every iteration creates a NEW complete window by sliding,
                                         // so we push/print the maximum INSIDE the loop.
    }

    return res;
}

int main(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8;
    int k = 3;
    vector<int> result = slidingWindowMaxUsingDeque(arr, n, k);

    for (int x : result) {
        cout << x << " ";
    }

}


// WHY DEQUE?
// ✔ Deque allows insertion and deletion from BOTH front and back
// ✔ We store INDICES in deque, NOT values
// ✔ Because of indices:
//  → we can easily check whether an element is OUT of current window
//  → dq.front() <= i - k  ⇒ element is no longer inside window
// ✔ Deque always stores indices in DECREASING order of values
// ✔ Front of deque ALWAYS stores index of MAX element of current window