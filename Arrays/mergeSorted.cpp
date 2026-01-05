#include <iostream>
using namespace std;

void mergeSortedArr (int arr1[],int n,int arr2[], int m){ // (Using extra array) T.C O(n+m)   S.C O(n+m)
    int result [n+m];
    int i=0;int j=0;int k=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            result[k]=arr1[i];
            k++;
            i++;
        }
        else{
            result[k]=arr2[j];
            k++;
            j++;
        }
    }
    while (i<n){
        result[k]=arr1[i];
        k++;
        i++;
    }
    while(j<m){
        result[k]=arr2[j];
        k++;
        j++;
    }
    for(int x=0; x<n+m; x++){
        cout<<result[x]<<" ";
    }
}
void mergeSortedArrays (int a[], int n, int b[], int m){  // Optimal in-place approach (when first array has extra space)                                         
   int i = n-1;   // T.C O(n+m)  S.C O(1)
   int j = m-1;   
   int k = n+m-1;

   while(i>=0 && j>=0){
    if(a[i]>b[j]){
        a[k]=a[i];  // as we are inserting from back so bigger element at end
        k--;
        i--;
    }
    else{
        a[k]=b[j];
        k--;
        j--;
    }
   }
   while(j>=0){  // when b has more elements then a
    a[k]=b[j];
    k--;
    j--;
   }
   for(int x=0; x<n+m; x++){
    cout<<a[x]<<" ";
   }
}
int main(){

int a[5] = {1,5};
int b[] = {2, 4, 6};
mergeSortedArrays(a, 2, b, 3);
}

/*  int main() {
        vector<int> a = {1, 3, 5};
        vector<int> b = {2, 4, 6};
        vector<int> result;           // Using STL (Simplest)   T.C O(n+m)  S.C O(n+m)

        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result)); // insert from end 

        for (int x : result) cout << x << " ";
    }
*/
