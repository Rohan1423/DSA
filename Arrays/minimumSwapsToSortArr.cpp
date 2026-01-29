#include <iostream>
using namespace std;

int minSwapsBrute (int arr[],int n){
    int sorted[n];

    for(int i=0; i<n; i++){
        sorted[i] = arr[i];
    }
    sort(sorted,sorted+n);
    int swaps = 0;

    for(int i=0; i<n; i++){
        if(arr[i]!=sorted[i]){
            for(int j=i+1; j<n; j++){
                if(arr[j]==sorted[i]){
                    swap(arr[i],arr[j]);
                    swaps++;
                    break;
                }
            }
        }
    }
    return swaps;
}

int main (){
    int arr[] = {4, 3, 2, 1};
    int n=4;
    cout<<minSwapsBrute(arr,n)<<endl;
}