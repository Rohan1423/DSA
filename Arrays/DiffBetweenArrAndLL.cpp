// -> Difference Between Array and Linked List
// Feature	                  Array	                  Linked List
// Memory Allocation	     Continuous (one block)	 Non-continuous (scattered)
// Access by Index	         Fast O(1)	             Slow O(n)
// Insertion / Deletion	     Costly O(n)	         Easy O(1)*
// Memory Usage	             Less (only data)	     More (data + pointer)
// Cache Friendly	         Yes	                 No
// Size	                     Fixed (static).     	 Dynamic (grows/shrinks)
// Traversal	             Easy using index	     Sequential only
// Implementation	         Simple	                 More complex

// * O(1) only if position/node is already known

// -> Key Concept Difference (Very Important)

// -> Array
// [10][20][30][40]

// Stored next to each other

// You can directly jump to any index

// -> arr[2] → instant access



// -> Linked List
// 10 → 20 → 30 → 40 → NULL

// Each node stores:

// data

// pointer to next node

// Must start from head

// -> To reach 30, you must go through 10 → 20 → 30



// -> Time Complexity Comparison
// Operation	         Array	Linked List
// Access element	     O(1)	O(n)
// Insert at beginning	 O(n)	O(1)
// Insert at end	     O(1)*	O(n)/O(1)**
// Delete at beginning	 O(n)	O(1)
// Search	             O(n)	O(n)

// * if space exists
// ** if tail pointer exists



// -> When to Use What?
// -> Use Array when:

// Need fast access

// Size is known

// Less insert/delete operations

// -> Example:

// Static data

// Matrix

// Lookup tables

// -> Use Linked List when:

// Size is dynamic

// Many insertions/deletions

// Memory not contiguous

// -> Example:

// Undo/Redo operations

// Music playlist

// Implementing stacks & queues



// -> “Array provides fast access but slow insertion, while linked list provides fast insertion but slow access.”