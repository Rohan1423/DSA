#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(int arr[], int n) {
    unordered_set<int> st;

    // Insert all elements into the set
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int longest = 0;

    // Traverse each element
    for (int i = 0; i < n; i++) {

        // Check if arr[i] is the start of a sequence
        if (st.find(arr[i] - 1) == st.end()) {

            int currentNum = arr[i];
            int currentStreak = 1;

            // Count consecutive numbers
            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                currentStreak++;
            }

            // Update longest sequence
            longest = max(longest, currentStreak);
        }
    }

    return longest;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(arr, n);

    return 0;
}