// -> What is Fragmentation?

// Fragmentation is the wastage of memory that happens when memory is not used efficiently.

// Even though memory is free, it cannot be used properly by processes.



// Why Does Fragmentation Happen?

// Because:

// Processes request different sizes of memory

// Memory is allocated and freed over time

// Free memory gets broken into pieces (fragments)



// Types of Fragmentation

// -> Internal Fragmentation

// -> Meaning:
// Wasted memory inside an allocated block

// -> You give a process more memory than it needs

// Example:

// Block size = 10 KB

// Process needs = 6 KB

// [ Process 6 KB | Wasted 4 KB ]


// ➡ That 4 KB cannot be used by anyone else

// ✔ Happens in fixed-size allocation



// -> External Fragmentation

// -> Meaning:
// Free memory exists but is scattered in small pieces

// Example:
// Free 5 KB | Used | Free 3 KB | Used | Free 4 KB


// Total free memory = 12 KB
// But a process needs 10 KB contiguous memory
// (No single block is large enough)

// ✔ Happens in variable-size contiguous allocation

// Simple Difference Table
// Internal Fragmentation	External Fragmentation
// Waste inside block	Waste between blocks
// Block too large	Free memory scattered
// Fixed partitions	Variable partitions
// Memory allocated but unused	Memory free but unusable
// Real-Life Example
// -> Internal Fragmentation

// You book a large suitcase but only fill half of it
// ➡ Space inside is wasted



// -> External Fragmentation

// You have many small boxes, but none is big enough for a large item
// ➡ Total space exists, but not usable

// How to Reduce Fragmentation?

// Internal → Use variable-sized blocks

// External → Memory compaction or paging



// Fragmentation is a condition where memory space is wasted due to inefficient allocation, even though sufficient memory may be available.