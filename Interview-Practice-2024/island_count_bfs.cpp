




void traverse_bfs(vector<vector<int>> &matrix, int r, int c) {
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    queue<pair<int,int>> Q;
    Q.push(make_pair(r,c));
    while(!Q.empty()) {
        int top_row = Q.top().first;
        int top_col = Q.top().second;
        Q.pop();
        for(int k = 0; k < directions.size(); k++) {
            int new_row = directions[k][0] + top_row;
            int new_col = directions[k][1] + top_col;
            if(check_boundary_conditions_validity(matrix, new_row, new_col)) {
                Q.push(make_pair(new_row, new_col));
                matrix[new_row][new_col] = 0;
            }
        }
    }
    return;
}

bool check_boundary_conditions_validity(vector<vector<int>> &matrix, int r, int c) {
    if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] == 0) {
        return false;
    }
    return true;
}

int count_islands(vector<vector<int>> &matrix) {
    // Write your code here.
    int island_count = 0;
    int m = matrix.size(); 
    int n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; i < n; j++) {
            if(matrix[i][j] == 1) {
                traverse_bfs(matrix, i, j);
                island_count++;
            }
        }
    }
    return island_count;
}
