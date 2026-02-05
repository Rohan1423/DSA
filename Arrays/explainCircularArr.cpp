// -> What is a Circular Array?

// A circular array is an array where the end connects back to the beginning.

// -> After the last index, we wrap around to index 0.

// Visually:

// 0 → 1 → 2 → 3 → 4
// ↑                 ↓
// ← ← ← ← ← ← ← ← ←


// So instead of stopping at the end, we reuse the same array in a circular way.

// -> Normal Array vs Circular Array
// Normal Array
// Index: 0  1  2  3  4
// Value: a  b  c  d  e


// After index 4, array ends

// Cannot reuse freed space easily

// Circular Array
// Index: 0  1  2  3  4
// Value: a  b  c  d  e
//           ↑         ↓
//           ← ← ← ← ←


// After index 4, we go back to 0

// Memory is reused efficiently

// -> How Do We Move in a Circular Array?
// -> Using Modulo %
// nextIndex = (currentIndex + 1) % n;


// Example:

// n = 5
// currentIndex = 4

// (4 + 1) % 5 = 0


// -> Wraps back to start.

// -> Simple Example
// int arr[5] = {10, 20, 30, 40, 50};
// int n = 5;

// int i = 0;
// for (int count = 0; count < 10; count++) {
//     cout << arr[i] << " ";
//     i = (i + 1) % n;
// }


// Output:

// 10 20 30 40 50 10 20 30 40 50

// -> Where Circular Array is Used (IMPORTANT)
// -> Circular Queue (MOST COMMON)

// In a normal queue, once rear reaches end:

// Cannot insert even if front has empty space

// In a circular queue:

// Rear wraps around

// Space is reused efficiently

// -> Used in:

// OS scheduling

// Producer–Consumer problem

// Buffers

// -> Sliding Window Problems

// Example:

// Circular maximum sum

// Circular subarray

// arr = [5, -3, 5]
// Output = 10  (wraps around)


// -> We treat array as circular.

// -> Buffer / Streaming Data

// Used in:

// Audio buffers

// Video streaming

// Network packet buffers

// Why?

// Continuous data

// Old data overwritten by new data

// -> Round Robin Scheduling

// Example:

// CPU time-sharing

// Each process gets fixed time slice

// After last process → go back to first.

// -> Deques (Double-ended queues)

// Many deque implementations internally use circular arrays.

// -> Circular Array vs Linked List
// Feature	            Circular Array	    Linked List
// Memory	            Contiguous	        Non-contiguous
// Cache friendly	    Yes	                No
// Wrap around	        Easy with %	        Needs pointers
// Random access	    O(1)	            O(n)



// “A circular array treats the array as if the last index connects back to the first, allowing efficient reuse of space.”


// -> Common Mistakes

// Forgetting % n
// Infinite loops
// Wrong full/empty conditions in circular queue


// -> Key Formula to Remember
// next = (index + 1) % n;
// prev = (index - 1 + n) % n;