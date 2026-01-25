#include <iostream>
#include <unordered_set>
using namespace std;

bool subarrayWithSumBrute(int arr[], int n, int target) { // Brute Force T.C O(n x n). S.C O(1)
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == target)
                return true;
        }
    }
    return false;
}

bool subarrayWithSumBetter(int arr[],int n, int target){  // Better Approach T.C O(n)  S.C O(n)
    unordered_set<int> prefixSet;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==target){
            return true;
        }
        if(prefixSet.find(sum-target) !=prefixSet.end()){  // find in already stored sum value
            return true;
        }
        prefixSet.insert(sum);
    }
    return false;
}

bool subarrayWithSumOptimal(int arr[],int n, int target){  // Optimal Approach T.C O(n)  S.C O(1) (Fails if negative numbers exist)
    int start=0; int sum=0;
    for(int end=0; end<n; end++){
        sum+=arr[end];

        while(sum>target){
            sum-=arr[start];
            start++;
        }
        if(sum==target){
            return true;
        }
    }
    return false;
}

int main(){
int arr[] = {1, 4, 20, 3, 10, 5};
int target = 33;
int n=6;
cout<<subarrayWithSumOptimal(arr,n,target)<<endl;
}