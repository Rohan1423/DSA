#include <iostream>
#include <vector>
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

void slidingWindowMaxUsingDeque(int arr[],int n, int k){  // Optimal Approach (Using Deque) TC: O(n), SC: O(k)
    deque<int>dq;
    vector<int>res;
    for(int i=0;i<k;i++){
        while(dq.size()>0 && arr[dq.back()]<=arr[i]){  // remove if last pushed element is smaller than current element
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k; i<n; i++){
        while(dq.size()>0 && arr[dq.front()]<=i-k){  // remove if deque has element which is not in current window
            dq.pop_front();
        }
        while(dq.size()>0 && arr[dq.back()] <=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8;
    int k = 3;
    slidingWindowMaxUsingDeque(arr,n,k);
}