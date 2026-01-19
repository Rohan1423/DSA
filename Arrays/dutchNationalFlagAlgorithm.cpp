#include <iostream>
using namespace std;

void sort012(int arr[], int n) {  // Optimal Approach (Dutch National Flag Algorithm) T.C: O(n) S.C: O(1)

    int left = 0;        // Index where next 0 should be placed
    int mid  = 0;        // Current element being checked
    int high = n - 1;    // Index where next 2 should be placed

    // Process elements until mid crosses high
    while (mid <= high) {

        // Case 1: current element is 0
        if (arr[mid] == 0) {
            // Put 0 in the left zone
            swap(arr[left], arr[mid]);

            // Move both pointers forward
            // Because:
            // - 0 is now correctly placed
            // - Element at mid is already checked
            left++;
            mid++;  // // - The element swapped from mid to left is KNOWN (as we are travelling from left to right so we already know the right element)
        }

        // Case 2: current element is 1
        else if (arr[mid] == 1) {
            // 1 is already in the correct middle zone
            // Nothing to swap, just move mid forward
            mid++;
        }

        // Case 3: current element is 2
        else {
            // Put 2 in the right zone
            swap(arr[mid], arr[high]);

            // Decrease high pointer
            // DO NOT increment mid here!
            // Because:
            // - The element swapped from high to mid is UNKNOWN (as we are travelling from left to right so we don't know the right element)
            // - It could be 0, 1, or 2
            // - So we must re-check it
            high--;
        }
    }
}

// sort(arr, arr + n); → O(n log n) X

int main (){
     int arr[] = {2, 0, 2, 1, 1, 0};
     int n=6;
     sort012(arr,n);
     for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
     }
}