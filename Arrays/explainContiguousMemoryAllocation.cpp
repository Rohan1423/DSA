// -> What is Contiguous Memory Allocation?

// Contiguous memory allocation means that a program or process is given one single, continuous block of memory.

// -> All the memory locations assigned to a process are next to each other in RAM.

// Think of it like booking seats in a movie theater:

// You need 5 seats

// All 5 must be together in one row

// You can’t split them across rows

// That’s contiguous allocation 

// Simple Example

// Assume memory addresses like this:

// 1000 1001 1002 1003 1004 1005 1006 1007


// If a process needs 4 units of memory, it might get:

// 1002 1003 1004 1005

// ✔ All addresses are continuous
// ✔ Easy to manage



// How the OS Tracks It

// The OS stores:

// Starting address

// Size (limit)

// Example:

// Process	Start	Size
// P1	1000	5
// P2	1005	3



// Accessing memory becomes fast:

// Physical Address = Start Address + Offset


// Types of Contiguous Allocation

// -> Fixed Partitioning

// Memory divided into fixed-size blocks

// One process per block

// Problem:
// -> Internal Fragmentation (wasted memory inside a block)

// Example:

// Block size = 10 KB

// Process needs = 6 KB
// ➡ 4 KB wasted

// -> Variable Partitioning

// Memory blocks are created dynamically

// Size depends on process need

// Problem:
// -> External Fragmentation (free memory exists but not contiguous)

// Example:

// Free 5 KB | Used | Free 3 KB | Used | Free 4 KB

// Total free = 12 KB
// But no single block of 12 KB


// Allocation Strategies

// When choosing a free block:

// -> First Fit

// Take the first block that is large enough

// Fast

// -> Best Fit

// Take the smallest block that fits

// Reduces waste but slower

// -> Worst Fit

// Take the largest block

// Leaves large fragments


// Advantages

// Simple to implement

// Fast memory access

// Easy address calculation

// Low overhead


// Disadvantages

// External fragmentation

// Process size must be known in advance

// Difficult to grow process dynamically

// Memory compaction may be needed


// Real-World Analogy

// -> Warehouse storage

// Each customer’s goods must be stored in one continuous space

// If space is scattered, you can’t store a big item even if total space is enough



// Contiguous memory allocation assigns a process a single, continuous block of physical memory.
// It is simple and fast but suffers from fragmentation issues.