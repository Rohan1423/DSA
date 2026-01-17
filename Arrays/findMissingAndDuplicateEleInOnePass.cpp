#include <iostream>
using namespace std;

void findMissingAndDuplicate(int arr[], int n) {  // XOR Method  T.C O(n)  S.C O(1)
    int xorAll = 0;

    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
        xorAll ^= (i + 1);
    }

    int setBit = xorAll & -xorAll;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit) x ^= arr[i];
        else y ^= arr[i];

        if ((i + 1) & setBit) x ^= (i + 1);
        else y ^= (i + 1);
    }

    // Identify which is missing
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == x) count++;

    if (count == 2)
        cout << "Duplicate: " << x << "\nMissing: " << y;
    else
        cout << "Duplicate: " << y << "\nMissing: " << x;
}

int main (){
    int arr[] = {1, 2, 2, 4, 5};
    int n = 5;
    findMissingAndDuplicate(arr,n);
}