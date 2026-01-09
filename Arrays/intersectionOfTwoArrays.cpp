#include <iostream>
using namespace std;

void intersectionOfTwoArrays(int arr1[],int arr2[],int n,int m){  // Brute Force (Basic approach)
    for(int i=0;i<n;i++){                                         // Compare every element of array A with every element of array B.
        for(int j=0; j<m; j++){                                   // T.C O(n x m)  S.C O(1)
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                break;  // avoid duplicate printing  (“I found a[i] in b[], no need to check further”)
            }
        }
    }
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {2, 2, 4};

    intersectionOfTwoArrays(a, b, 3, 3);

    return 0;
}