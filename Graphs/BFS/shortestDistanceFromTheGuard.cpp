/*Shortest Distance From the Guard



Problem Statement:



You are given a 2D character grid of size n * m. Each element of the grid is either a GUARD, an OPEN space or a WALL. Every GUARD can move up, down, left and right in the open space. They cannot move on the wall.



Find, for every cell, the distance from the nearest guard cell. Consider -1 as this distance for WALL cells and unreachable cells.



Input/Output Format For The Function:



Input Format:



You will be given a string array rowStr of size n, where each string rowStr[i] is of length m. rowStr represents the grid. Each character in the grid will be G, O or W.



G - Guard

O - Open space

W - Wall



Output Format:



Return 2D integer array resArr, of size n * m, where resArr[i][j] representing the distance from a cell in the ith row and jth column to its nearest guard.

Put -1 in case of wall cells and unreachable cells.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting no. of rows in input grid, which is also a size of array rowStr.

The second line of input should contain an integer m, denoting no. of columns in input grid.

In next n lines, the ith line should contain a string rowStr[i], denoting value at index i of rowStr.



If n = 5, m = 5 and rowStr = [“OOOOG”, “OWWOO”, “OOOWO”, “GWWWO”, “OOOOG”], then the input should be:



5

5

OOOOG

OWWOO

OOOWO

GWWWO

OOOOG



Output Format:



Output 2D array of integers resArr will be of same size of given 2D array i.e. n * m.



There will be n lines of output, where the ith line contains m space separated integers. So, jth integer in ith line is value resArr[i][j], denoting value at index (i, j) of resArr.



For input n = 5, m = 5 and rowStr = [“OOOOG”, “OWWOO”, “OOOWO”, “GWWWO”, “OOOOG”], output will be:



3 3 2 1 0

2 -1 -1 2 1

1 2 3 -1 2

0 -1 -1 -1 1

1 2 2 1 0



Constraints:



1 <= n, m <= 10^3


*/

vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>> grid) {
/*
case 1 : if(cellNum == G) cellNum = 0;
case 2 : else if (cellNum == W) cellNum = -1;
case 3 : else computeVal //for cellNum == O
computeVal(matrix, row, col) {
    int count = 0; 
    boundary check
} (m*n)*(m*n)
Better approach: Start from 'G' and find the values. Stop when you encounter another G or your current count > existing count in that cell (G * (m*n)) {BFS}
Best Approach : Put all the Gs in the queue and apply BFS. 
*/

}
