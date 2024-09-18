/*start BFS at {0,0} 
if that's not 0, drop and return -1.
If that's 0, look at its 8 neighbors and keep adding to the q if they're zero and keep track of the distance using a separate variable. Parent tracking is essential if we need to return the path
at every iteration until Q is not empty, check if we've reached the end of the matrix (m-1, n-1). If we have, return the distance + 1
if we've reached an enpty Q, return -1 in the end 
*/


int shortest_path_length(vector<vector<int>> &matrix) {
    // Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    if(m == 0 && n == 0)
        return -1;
    if(matrix[0][0] == 1)
        return -1;
    queue<pair<int,int> Q;
    vector<vector<int>> distance(m, vector<int>(n, 0));
    Q.push(make_pair(0,0));
    vector<vector<int>> directions = {{0,0},{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{1,1}};
    while(!Q.empty()) {
        int row = Q.top().first;
        int col = Q.top().second;
        for(int i = 0; i < 8; i++) {
            int new_row = row + directions[i][0];
            int new_col = col + directions[i][1];
            if(new_row == m && new_col == n) {
                return distance[row][col] + 1;
            }
            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && matrix[new_row][new_col] == 0) {
                distance[new_row][new_col] == distance[row][col] + 1;
                Q.push(make_pair(new_row, new_col));
            }
        }
    }
    return -1;
}
