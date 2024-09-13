class Solution {
public:

    bool boundary_conditions(int r, int c, int m, int n, vector<vector<bool>> visited) {
        if(c < 0 || c >= n || r < 0 || r >= m || visited[r][c] == true)
            return false;
        return true;
    }

    int traverse_bfs(vector<vector<int>>& grid, int r, int c, int m, int n, vector<vector<bool>> visited) {
        vector<vector<int>> distance(m, vector<int>(n,0));
        queue <pair<int,int>> Q;
        Q.push(make_pair(r,c));
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
        while(!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            if(row == m - 1 && col == n -1) {
                return distance[row][col];
            }
            for(int k = 0; k < directions.size(); k++) {
                int new_row = directions[k].first + row;
                int new_col = directions[k].second + col;
                if(grid[new_row][new_col] == 0 && boundary_conditions(new_row, new_col, m, n, visited)) {
                    distance[new_row][new_col] = distance[row][col] + 1;
                    visited[new_row][new_col] = 1;
                    Q.push(make_pair(new_row, new_col));
                }
            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minimum = INT_MAX;
        vector<vector<bool>> visited(m, vector<bool> (n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 && boundary_conditions(i, j, m, n, visited)) {
                    visited[i][j] = 1;
                    int distance = traverse_bfs(grid,i,j,m,n,visited);
                    if(distance != -1 && distance < minimum) {
                        minimum = distance;
                    }
                }
            }
        }
        return (minimum != INT_MAX)?minimum:-1;
    }
};

//Shortest path can be found by BFS
//if 0, start looking in all 8 directions. 
//each element in the matrix should have a distance and visited variable associated with it
//if not visited and it is 0 and in bounds, add it to the Q, increment distance = curr_distance + 1 and visited is set to true, add it to the Q and move on to the next.
//if you reach the end of the matrix, return distance
//if you don't, keep going over the other elements in the matrix.
//if we reach the end without finding a path, return -1;


Working solution: 

class Solution {
public:

    bool boundary_conditions(int r, int c, int m, int n) {
        if(c < 0 || c >= n || r < 0 || r >= m)
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        vector<vector<bool>> visited(m, vector<bool>(n,0));
        vector<vector<int>> distance(m, vector<int>(n,0));
        queue <pair<int,int>> Q;
        Q.push(make_pair(0,0));
        visited[0][0] = 1;
        distance[0][0] = 1;
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
        while(!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            if(row == m - 1 && col == n -1) {
                return distance[row][col];
            }
            for(int k = 0; k < directions.size(); k++) {
                int new_row = directions[k].first + row;
                int new_col = directions[k].second + col;
                if(boundary_conditions(new_row, new_col, m, n) && !visited[new_row][new_col] && grid[new_row][new_col] == 0) {
                    distance[new_row][new_col] = distance[row][col] + 1;
                    visited[new_row][new_col] = 1;
                    Q.push(make_pair(new_row, new_col));
                }
            }
        }
        return -1;
    }
};

