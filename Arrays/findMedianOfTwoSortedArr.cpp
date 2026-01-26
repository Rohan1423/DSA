#include <iostream>
using namespace std;

double findMedian(int a[], int n, int b[], int m) {  // Brute Force T.C O(n+m) S.C O(n+m)
    int merged[n + m];
    int i = 0, j = 0, k = 0;

    // Merge arrays
    while (i < n && j < m) {
        if (a[i] <= b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    while (i < n) merged[k++] = a[i++];
    while (j < m) merged[k++] = b[j++];

    int total = n + m;

    // Find median
    if (total % 2 == 1)
        return merged[total / 2];
    else
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
}
int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};

    int n = 3;
    int m = 3;

    cout << "Median = " << findMedian(a, n, b, m);
    return 0;
}