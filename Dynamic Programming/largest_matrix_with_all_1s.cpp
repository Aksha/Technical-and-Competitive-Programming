/*
Given a two-dimensional binary matrix, find the largest square submatrix with all 1s.

Example
Input: [
[1, 0, 0],
[0, 1, 1],
[0, 1, 1]
]

Output: 2
The 1s in bold form a square submatrix 2x2 with all 1s. That’s the largest one. Length of its side is 2.

Notes
Input Parameters: There are three arguments, n, m, mat denoting the number of rows, number of columns of the matrix and the two-dimensional matrix of integers.
Output: Return an integer, the length of the side of the largest square submatrix with all 1s.

Constraints:
1 <= n, m <= 1000 


Custom Input
Input Format: The first line of input should contain a single number n, denoting the number of rows of input matrix mat. Second line should contain a single integer m, denoting the number of columns of input matrix mat. In the next n lines, each line should contain m space separated numbers. jth number in ith line of these n lines is mat[i][j], denoting the number at ith row and jth column of matrix. If n=3, m=3 and mat=[ [1,0,0], [0,1,1], [0,1,1]], then input should be:

3

3

1 0 0

0 1 1

0 1 1



Output Format: There should be a single number representing the result. If n=3, m=3 and mat=[ [1,0,0], [0,1,1], [0,1,1]], then output should be:

2
*/

