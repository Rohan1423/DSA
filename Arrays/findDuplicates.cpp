#include <iostream>
using namespace std;
#include <algorithm>
void findDuplicates (int arr[],int n){  // T.C O(n) – traverse array S.C O(n) – unordered_map
    unordered_map<int,int> freq;  // Map to store frequency

    cout<<"Duplicates :";

    for (int i=0; i<n; i++){
        freq[arr[i]]++; // C++ automatically initializes missing keys to 0.Then ++ increases it:freq[2] = 0;  // default value then freq[2] = 1;
    }

    for(auto x : freq){  // x.first → number x.second → frequency
        if(x.second>1){  
          cout<<x.first;
        }
    }
    cout<<endl;
}

void findDuplicatesUsingSort(int arr[],int n){  // T.C  O(n log n) – for sorting S.C  O(1) – in-place

    //arr and arr + n are pointer arithmetic concepts

    sort(arr,arr+n);  // Sort the array from index 0 to index n-1 in ascending order (Left inclusive, right exclusive)   
                      //   Index:   0   1   2   3
                      //   Value:   5   2   8   1
                      //            ↑               ↑
                      //           arr          arr + n

    cout<<"Duplicates :";
    for (int i=0; i<n-1; i++){
        if(arr[i]==arr[i+1]){
            if(i==0||arr[i]!=arr[i-1]){  // Print only if this is the first time we are seeing this duplicate number
                cout<<arr[i];
            }
        }
    }
    cout<<endl;
}

void findDuplicatesUsingIndexes (int arr[], int n) { // If the array contains numbers from (1 to n), we can use the index as a marker:
    cout<<"Duplicates :";
    for (int i=0; i<n;i++){
        int indexes = abs(arr[i])-1;  // map value to index
        if(arr[indexes]<0){
            cout<<abs(indexes+1); // already visited → duplicate
        }         // T.C O(n) S.C O(1)
        else{
            arr[indexes] = -arr[indexes];  // mark visited
        }
    }
    cout<<endl;
}
int main (){
    int arr[] = {1,2,3,1,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    findDuplicatesUsingIndexes(arr,n);
}
