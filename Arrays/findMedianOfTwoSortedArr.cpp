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

double findMedianBetter(int a[], int n, int b[],int m){  // Better (Two pointers, no extra array)  T.C O(n+m) S.C O(1)
    int total = n+m;
    int mid1 = (total-1)/2;
    int mid2 = total/2;
    int prev=0;
    int curr=0;
    int count=0;
    int i=0;
    int j=0;
    while(count<=mid2){
        prev=curr;
        if(i<n && (j>=m || a[i]<=b[j])){
            curr=a[i];
            i++;
        }
        else{
            curr=b[j];
            j++;
        }
        count++;
    }
    if(total%2==1){
        return curr;
    }
    else{
        return (prev+curr)/2.0;
    }
}

double findMedianOptimal(int a[],int n,int b[],int m){  // Optimal (Binary Search) BEST T.C O(log(min(n,m)) S.C O(1)
    // Ensure a is smaller array
    if (n > m) return findMedian(b, m, a, n);

    int low = 0, high = n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int left1  = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int left2  = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : a[cut1];
        int right2 = (cut2 == m) ? INT_MAX : b[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n + m) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};

    int n = 3;
    int m = 3;

    cout << "Median = " << findMedianOptimal(a, n, b, m);
    return 0;
}