#include <iostream>
using namespace std;
#include <unordered_set>
#include <unordered_map>
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

void intersectOfTwoArr(int arr1[],int arr2[],int n,int m){ // Using Sorting + Two Pointers T.C O(n log n + m log m). S.C O(1)
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i=0; int j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            int val=arr1[i];
            i++;
            j++;
        
           // while(i<n && arr1[i]==val)i++;  // SKIP duplicates in a
           // while(j<m && arr2[j]==val)j++;  // SKIP duplicates in b
           
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}
void interSectOfTwoArrs(int a[],int b[],int n,int m){ // Using Hash Set (Optimal for unsorted arrays) T.C O(n+m). S.C O(n)
    unordered_set<int> s;                             // Loops are not nested, so complexities add, not multiply
    for(int i=0; i<n;i++){
        s.insert(a[i]);
    }
    for(int j=0; j<m; j++){
        if(s.find(b[j]) != s.end()){ // find(10) → returns iterator to 10 if found , s.end() → means not found
          cout<<b[j]<<" ";
          s.erase(b[j]); // // avoid duplicates
        }
    }
}

void intersectionOfTwoArraysss(int a[], int b[], int n, int m){ // If duplicates count matters (Multiset / Frequency Map)
    unordered_map<int,int> freq;                                // T.C O(n+m). S.C O(n)
    for(int i=0; i<n; i++){
        freq[a[i]]++; // initialize & increament frequency
    }
    for(int j=0; j<m; j++){
        if(freq[b[j]]>0){
            cout<<b[j]<<" ";
            freq[b[j]]--;  // decreament frequency
        }
    }
}

int main() {
    int a[] = {2, 2, 3};
    int b[] = {2, 3, 4};

    intersectionOfTwoArraysss(a, b, 3, 3);

    return 0;
}