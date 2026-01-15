#include <iostream>
using namespace std;

void productOfArrExceptSelf (int arr[],int n){ // Brute Force Approach T.C O(n x n) S.C O(1)
    for (int i=0; i<n; i++){
        int product=1;
        for (int j=0; j<n; j++){
            if(i!=j){
                product *=arr[j];
            }
        }
        cout<<"product of "<<arr[i]<<" is : "<<product<<"\n";
    }
}

void productOfArrayExceptSelf(int arr[], int n){ // Using Prefix & Suffix Products (Optimal) T.C O(n) S.C O(n)
    int prefix[n];
    int suffix[n];
    int result[n];
    prefix[0]=1; // Left products
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * arr[i-1];
    }
    suffix[n-1]=1; // Right products
    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * arr[i+1];
    }

    for(int i=0; i<n; i++){
        result[i] = prefix[i] * suffix[i];  // (product of all elements to the LEFT of i)×(product of all elements to the RIGHT of i)
    }

    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
}

void prodOfArrExceptSelf(int nums[], int n) { // Optimal (O(1) Extra Space) T.C O(n) S.C O(1)
    int result[n];

    // Step 1: Prefix products
    result[0] = 1;
    for (int i = 1; i < n; i++)
        result[i] = result[i - 1] * nums[i - 1];

    // Step 2: Suffix product on the fly
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {  // First loop builds LEFT products Second loop multiplies RIGHT products
        result[i] *= suffix;
        suffix *= nums[i];
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}

int main (){
    int arr[]={1,2,3,4};
    prodOfArrExceptSelf(arr,4);
}