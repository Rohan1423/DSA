#include <iostream>
#include <vector>
using namespace std;

int minSwapsBrute (int arr[],int n){
    int sorted[n];

    for(int i=0; i<n; i++){
        sorted[i] = arr[i];
    }
    sort(sorted,sorted+n);
    int swaps = 0;

    for(int i=0; i<n; i++){
        if(arr[i]!=sorted[i]){
            for(int j=i+1; j<n; j++){
                if(arr[j]==sorted[i]){
                    swap(arr[i],arr[j]);
                    swaps++;
                    break;
                }
            }
        }
    }
    return swaps;
}

int minSwaps(int arr[], int n) {  // Optimal Approach T.C O(n log n)  S.C O(n)
    vector<pair<int,int>> v;

    // Store value and original index
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }

    // Sort by value
    sort(v.begin(), v.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {

    // Skip if:
    // 1) already visited → this index is part of a cycle already counted
    // 2) element already in correct sorted position → no swap needed
    if (visited[i] || v[i].second == i)
        continue;

    int cycleSize = 0;
    int j = i;

    // Follow the cycle:
    // jump to the index where current element originally came from
    // keep going until we come back to a visited index
    while (!visited[j]) {
        visited[j] = true;        // mark current index as processed
        j = v[j].second;          // move to next index in the cycle
        cycleSize++;              // count elements in this cycle
    }

    // A cycle of size k needs (k - 1) swaps to fix
    if (cycleSize > 1)
        swaps += (cycleSize - 1);
}


    return swaps;
}

int main (){
    int arr[] = {4, 3, 2, 1};
    int n=4;
    cout<<minSwaps(arr,n)<<endl;
}