// -> Static Array vs Dynamic Array (Vector / ArrayList)
// Feature	              Static Array	                    Dynamic Array (vector / ArrayList)
// Size	                  Fixed (decided at compile time)	Grows / shrinks at runtime
// Memory Allocation	  Stack or static memory	        Heap memory
// Resize Possible?	      No	                            Yes (automatic)
// Insertion at End	      Not possible beyond size	        Easy (push_back)
// Access by Index	      O(1)	                            O(1)
// Insertion in Middle	  O(n)	                            O(n)
// Deletion	              O(n)	                            O(n)
// Memory Overhead	      Minimal	                        Extra memory for resizing
// Ease of Use	          Basic	                            Very easy & safe
// Language Examples	  int arr[5]	                    vector<int>, ArrayList


// -> Static Array (C / C++)

// Example
// int arr[5] = {1, 2, 3, 4, 5};

// Key Points

// Size is fixed

// Cannot add more elements

// Very fast

// Memory efficient

// -> Problem:

// arr[5] = 10; // Out of bounds

// -> Dynamic Array (C++ vector / Java ArrayList)
// Example (C++)
// vector<int> v;
// v.push_back(1);
// v.push_back(2);

// Example (Java)
// ArrayList<Integer> list = new ArrayList<>();
// list.add(1);
// list.add(2);

// Key Points

// Size increases automatically

// Uses heap memory

// Safer and flexible

// Slight overhead



// -> How Dynamic Array Works Internally (VERY IMPORTANT)

// When capacity is full:

// Create new bigger array

// Copy old elements

// Delete old array

// Example:

// Capacity = 4 → Full
// New capacity = 8
// Copy 4 elements → O(n)


// -> This is why amortized insertion is O(1)


// -> Time Complexity Comparison
// Operation	      Static Array	 Dynamic Array
// Access	          O(1)	         O(1)
// Insert at end	  O(1)           amortized
// Insert in middle   O(n)	         O(n)
// Delete	          O(n)	         O(n)
// Resize	          ❌             O(n)


// -> When to Use What?

// -> Use Static Array when:

// Size is fixed

// Performance is critical

// Low memory usage

// -> Example:

// Fixed matrix

// Competitive programming constraints



// -> Use Dynamic Array when:

// Size is unknown

// Frequent insertions

// Cleaner code

// -> Example:

// User input data

// DSA problems

// Production code



// “Static arrays have fixed size, while dynamic arrays can grow automatically using heap memory with slight overhead.”