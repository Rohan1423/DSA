#include <iostream>
#include <algorithm> // for sort
using namespace std;

int findMissingEle (int arr[],int n){   // T.C O(n) S.C O(1)

    int totalSum = n*(n+1)/2;
    int actualSum = 0;
    for(int i =0; i<n-1; i++){
        actualSum+=arr[i];
    }
    return totalSum-actualSum;


}

int findMissingEleUsingXor (int arr[], int n){   // T.C O(n) S.C O(1)
    int xor1 = 0;
    int xor2 = 0;
    for (int i =1; i<=n; i++){
        xor1 ^=i;
    }
    for (int i=0; i<n-1; i++){
        xor2 ^=arr[i];
    }
    return xor1 ^ xor2;
}

int findMissingEleUsingSort (int arr[], int n){   // T.C O(n log n)   S.C O(1)
    sort(arr,arr+n);  // n elements: arr[0] to arr[n-1]
    for (int i =0; i<n-1; i++){
        if(arr[i] != i+1){
            return i+1;
        }

    }
    return n;  // missing number is the last one, i.e., n.
}

int main () {
    int arr[] = {1,2,3,5};
    int n =5;
    cout<<findMissingEleUsingSort(arr,n)<<endl;
    return 0;
}