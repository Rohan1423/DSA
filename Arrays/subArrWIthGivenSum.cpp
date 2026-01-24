#include <iostream>
using namespace std;

bool subarrayWithSumBrute(int arr[], int n, int target) { // Brute Force T.C O(n x n). S.C O(1)
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == target)
                return true;
        }
    }
    return false;
}
