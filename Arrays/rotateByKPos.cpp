#include <iostream>
using namespace std;

void rotateOneByOne (int arr[], int n, int k){ // brute force(Solve the problem in the most straightforward way without caring about efficiency) approach                                             
        k= k%n;  // Because rotating by n, 2n, etc. gives the same array.   Do nothing when k < n
        while(k--){
            int last = arr[n-1];
            for(int i = n-1; i>0 ;i--){  //  T.C O(n x k) S.C O(1)
                arr[i]=arr[i-1];
            }
            arr[0] = last;

        }
}
void rotateRight (int arr[], int n, int k){  // Using Extra Array  T.C O(n)  S.C O(n)
    k=k%n;
    int temp[n];
    int index = 0;

    // Copy last k elements
    for(int i=n-k; i<n; i++){
        temp[index]=arr[i];
        index++;
    }
    // Copy first n-k elements
    for(int i=0; i<n-k; i++){
        temp[index++]=arr[i];
    }
    // Copy back to original array
    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    rotateRight(arr, n, k);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}