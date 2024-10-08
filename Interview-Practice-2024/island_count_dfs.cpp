
bool check_boundary_conditions_validity(vector<vector<int>> &matrix, int r, int c) {
    if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] == 0) {
        return false;
    }
    return true;
}



// void traverse_bfs(vector<vector<int>> &matrix, int r, int c) {
//     vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
//     queue<pair<int,int>> Q;
//     Q.push(make_pair(r,c));
//     while(!Q.empty()) {
//         int top_row = Q.front().first; //3
//         int top_col = Q.front().second; //4
//         Q.pop();
//         for(int k = 0; k < directions.size(); k++) {
//             int new_row = directions[k].first + top_row;
//             int new_col = directions[k].second + top_col;
//             if(check_boundary_conditions_validity(matrix, new_row, new_col)) {
//                 Q.push(make_pair(new_row, new_col));
//                 matrix[new_row][new_col] = 0;
//             }
//         }
//     }
//     return;
// }

void traverse_dfs(vector<vector<int>> &matrix, int r, int c) {
    if(check_boundary_conditions_validity(matrix, r, c) == false) {
        return;
    }
    matrix[r][c] = 0;
    traverse_dfs(matrix, r+1, c);
    traverse_dfs(matrix, r, c+1);
    traverse_dfs(matrix, r-1, c);
    traverse_dfs(matrix, r, c-1);
    return;
}

int count_islands(vector<vector<int>> &matrix) {
    // Write your code here.
    int island_count = 0;
    int m = matrix.size(); 
    int n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; i < n; j++) {
            if(matrix[i][j] == 1) {
                island_count++;
                traverse_dfs(matrix, i, j);
            }
        }
    }
    return island_count;
}
