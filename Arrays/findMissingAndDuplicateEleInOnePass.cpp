#include <iostream>
using namespace std;

void findMissingAndDuplicate(int arr[],int n){ // XOR Method T.C O(n) O(1)
    int xorAll=0;
    for(int i=0;i<n;i++){
        xorAll ^= arr[i]; // 1 ^ 2 ^ 2 ^ 4 ^ 5
        xorAll ^= (i+1);  // 1 ^ 2 ^ 3 ^ 4 ^ 5
    }                     // final xorAll = 2 ^ 3 but we get the result of 2 ^ 3 not the actual numbers
    int setBit = xorAll & -xorAll;  // find the rightmost setBit (i.e rightmost 1(ON)) in the binary form of the number...
    int x = 0;                      //  using this setBit we get the position where the bit is different in both the numbers of xorAll (2 and 3)
    int y = 0;
    for(int i=0; i<n; i++){  // Other numbers may enter the bucket,but only numbers with unequal counts survive XOR.

        if(arr[i] & setBit){  // check that seBit exists if so then, push in xor x (for actual elements in arr)
            x ^= arr[i];
        }
        else{                 // if do not exists then, push in xor y (for actual elements in arr)
            y ^= arr[i];
        }
        if((i+1) & setBit){  // check that seBit exists if so then, push in xor x (for 1...n)
            x ^= (i+1); 
        }
        else{                // if do not exists then, push in xor y (for 1...n)
            y ^= (i+1);
        }
    }                        // now in x and y we have the actual duplicate and missing number just need to differentiate
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){    // if count more than 1 then duplicate else count 0 means missing
            count++;
        }
    }
    if(count>1){
        cout<<"DUPLICATE IS : "<<x<<" MISSING IS : "<<y;
    }
    else{
        cout<<"DUPLICATE IS : "<<y<<" MISSING IS : "<<x;
    }
}  // The first loop only tells you that two numbers are wrong,
   // but it mixes them together (D ^ M).
   // The second loop is what separates them.



#include <iostream>
using namespace std;

void findDuplicateAndMissing(int arr[], int n){  // Optimal Approach (Math + Single Traversal) T.C O(n) S.C O(1)
    long long S = 0, S2 = 0;

    // Step 1: Compute sum and sum of squares of array elements
    // S  = sum of all array elements (includes duplicate)
    // S2 = sum of squares of all array elements (includes duplicate squared)
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * arr[i];
    }

    // Step 2: Compute sum and sum of squares of first n natural numbers
    // SN  = sum of numbers 1..n
    // S2N = sum of squares of numbers 1..n
    long long SN = n * (n + 1) / 2;
    long long S2N = n * (n + 1) * (2 * n + 1) / 6;

    // Step 3: Calculate differences
    // diff    = D - M  (duplicate - missing)
    // diffSq  = D^2 - M^2
    int diff = S - SN;
    int diffSq = S2 - S2N;

    // Step 4: Solve for sum = D + M using algebra
    // D^2 - M^2 = (D - M)(D + M) => diffSq = diff * sum => sum = diffSq / diff  (a^2 - b^2 = (a+b)(a-b))
    int sum = diffSq / diff;

    // Step 5: Solve for duplicate and missing numbers
    // D + M = sum, D - M = diff ==> 2D=diff+sum
    int duplicate = (diff + sum) / 2;
    int missing = sum - duplicate;

    // Step 6: Output
    cout << "Duplicate: " << duplicate << endl;
    cout << "Missing: " << missing << endl;
}




int main (){
    int arr[] = {1, 2, 2, 4, 5};
    int n = 5;
    findDuplicateAndMissing(arr,n);
}