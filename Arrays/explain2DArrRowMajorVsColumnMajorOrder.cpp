// -> 2D Array Basics

// A 2D array is like a matrix:

// int arr[3][4] =
// {
//   {1, 2, 3, 4},
//   {5, 6, 7, 8},
//   {9,10,11,12}
// };


// 3 rows, 4 columns

// arr[i][j] accesses row i and column j

// -> Row-Major vs Column-Major

// This is about **how the 2D array is stored in linear memory (1D memory).

// Memory is always 1D; multi-dimensional arrays are mapped into 1D memory.

// -> Row-Major Order

// Store row by row

// First store all elements of row 0, then row 1, then row 2, etc.

// Memory Layout:

// arr[0][0] → 1
// arr[0][1] → 2
// arr[0][2] → 3
// arr[0][3] → 4
// arr[1][0] → 5
// arr[1][1] → 6
// arr[1][2] → 7
// arr[1][3] → 8
// arr[2][0] → 9
// arr[2][1] → 10
// arr[2][2] → 11
// arr[2][3] → 12


// -> C / C++ use row-major order by default

// -> Column-Major Order

// Store column by column

// First store all elements of column 0, then column 1, etc.

// Memory Layout:

// arr[0][0] → 1
// arr[1][0] → 5
// arr[2][0] → 9
// arr[0][1] → 2
// arr[1][1] → 6
// arr[2][1] → 10
// arr[0][2] → 3
// arr[1][2] → 7
// arr[2][2] → 11
// arr[0][3] → 4
// arr[1][3] → 8
// arr[2][3] → 12


// -> Fortran / MATLAB use column-major order

// -> Index to Memory Formula
// Row-Major
// Address(arr[i][j]) = Base + (i * nCols + j) * size


// i → row index

// j → column index

// nCols → number of columns

// Column-Major
// Address(arr[i][j]) = Base + (j * nRows + i) * size

// j → column index

// i → row index

// nRows → number of rows

// -> Quick Example

// Array:

// arr[2][3] = {{1,2,3}, {4,5,6}}


// Memory layout:

// Row-Major	Column-Major
// 1 2 3 4 5 6	1 4 2 5 3 6
// -> Key Points to Remember

// Row-major → traverse rows first → C/C++ default

// Column-major → traverse columns first → MATLAB/Fortran default

// Impacts:

// Cache efficiency

// Performance of nested loops

// Libraries like BLAS / LAPACK

// -> Example Loop Efficiency
// Row-major efficient in C++
// for(int i=0; i<rows; i++)
//     for(int j=0; j<cols; j++)
//         sum += arr[i][j];      consecutive memory access

// Column-major access in C++ → slower (not consecutive)
// for(int j=0; j<cols; j++)
//     for(int i=0; i<rows; i++)
//         sum += arr[i][j]; 


// Row-major loops are faster because memory is contiguous in row direction → better cache performance.