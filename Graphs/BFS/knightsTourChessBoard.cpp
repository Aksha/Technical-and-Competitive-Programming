/*
Knight's Tour On A Chess Board



You are given a rows * cols chessboard and a knight that moves like in normal chess. Currently knight is at starting position denoted by start_row th row and start_col th col, and want to reach at ending position denoted by end_row th row and end_col th col.  The goal is to calculate the minimum number of moves that the knight needs to take to get from starting position to ending position.

start_row, start_col, end_row and end_col are 0-indexed. 



Example

Input:

rows = 5

cols = 5

start_row = 0

start_col = 0

end_row = 4

end_col = 1



Output: 3



3 moves to reach from (0, 0) to (4, 1):

(0, 0) -> (1, 2) -> (3, 3) -> (4, 1). 



Notes

Input Parameters:

There are six arguments. First is an integer denoting rows, second is an integer denoting cols, third is an integer denoting start_row, fourth is an integer denoting start_col, fifth is an integer denoting end_row and sixth is an integer denoting end_col.



Output: Return an integer.

If it is possible to reach from starting position to ending position then return the minimum number of moves that the knight needs to take to get from starting position to ending position.

If it is not possible to reach from starting position to ending position then return -1.



Constraints:

1 <= rows * cols <= 10^5
0 <= start_row, end_row < rows
0 <= start_col, end_col < cols
*/

struct Node{
    int v1;
    int v2;
    int level;
    Node(int inp1,int inp2,int inpLevel) : v1(inp1), v2(inp2), level(inpLevel) {}
};

bool isSafe(int row,  int col, int rows, int cols) {
    if(row < rows && col < cols && row >= 0 && cols >= 0)
        return true;
    return false;
}

int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {

    if(start_row == end_row && start_col == end_col)
        return 0;

    // Write your code here.
    queue<Node> Q;
    Node root(start_row,start_col,0);
    Q.push(root);
    vector<vector<int>> visited(rows, vector<int>(cols,-1));
    visited[start_row][start_col] = 1;
    int R[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int C[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    while(!Q.empty()) {
        //Calculate possible positions that the horse can go to from the given position.
        //Push each position in the queue.
        //Increment count by 1.
        //Calculate possible position from each of those positions in the queue.
        //If the end is reached, return count.
        int x = Q.front().v1;
        int y = Q.front().v2;
        int count = Q.front().level;
        Q.pop();
        for(int i = 0; i < 8; i++) {
            int nX = x+R[i];
            int nY = y+C[i];
            if(isSafe(nX,nY,rows,cols)) {
                if(visited[nX][nY] == -1) { // really tricky stuff. Why use 'int' instead of 'bool' here to prevent double free or corruption (out)
                    visited[nX][nY] = count+1;
                    if(nX == end_row && nY == end_col)
                        return count+1;
                    Node n(nX,nY,visited[nX][nY]);
                    Q.push(n);
                }
            }
        }
    }
    return -1;
}
