#https://neetcode.io/problems/rotting-fruit/question?list=neetcode150

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_count = 0;
        queue<pair<int,int>> Q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    fresh_count += 1;
                }
                if(grid[i][j] == 2) {
                    Q.push({i,j});
                }
            }
        }
        vector<int> row = {0,1,0,-1};
        vector<int> col = {1,0,-1,0};
        int minutes = 0;
        while(!Q.empty() && fresh_count > 0) {
            int length = Q.size();
            minutes += 1;
            for (int j = 0; j < length; j++) {
                int curr_row = Q.front().first;
                int curr_col = Q.front().second;
                Q.pop();
                //for each rotten fruit, find it's neighbors, if they're fresh, add it to the queue and reduce fresh_count; if they're 0 or 2, move on.
                for(int i = 0; i < 4; i++) {
                    int ro = curr_row + row[i];
                    int co = curr_col + col[i];
                    if(ro >= 0 && ro < grid.size() &&
                        co >= 0 && co < grid[0].size() && grid[ro][co] == 1) {
                        Q.push({ro,co});
                        fresh_count -= 1;
                        grid[ro][co] = 2;
                    }
                }
            }
        }
        return fresh_count == 0 ? minutes : - 1;
    }
};
