#include <iostream>
using namespace std;
#include <unordered_set>

bool pairWithGivenSum(int arr[],int tar, int n){ // Brute Force T.C O(n x n).S.C O(1)
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==tar){
                cout << "Pair found: " << arr[i] << ", " << arr[j] << endl;
                return true;
            }
        }
    }
    return false;
}

bool pairWithGivenSum1(int arr[],int tar, int n){ // Hashing (Most asked & optimal)  T.C O(n)  S.C O(1)
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        int need = tar-arr[i];
        if(s.find(need) !=s.end()){ // if exists
            cout << "Pair found: " << arr[i] << ", " << need << endl;
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

bool pairWithGivenSum2(int arr[],int tar, int n){ // Two Pointer (Array must be sorted) T.C O(n log n) S.C O(1)
    sort(arr,arr+n);
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==tar){
            cout<<"Pair found: "<<arr[left]<<", "<<arr[right]<<endl;
            return true;
        }
        else if((arr[left]+arr[right])<tar){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}

// If you need all pairs :-
// Use unordered_map<int,int> (frequency count)


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tar = 5;
    cout<<pairWithGivenSum2(arr,tar,n)<<endl;
}