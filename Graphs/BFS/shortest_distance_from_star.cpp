/*
m*n

input:
e * e e
e e e *
e e * e

output:
1 0 1 1
1 1 1 0
2 1 0 1


input:
1 * 1 e
1 1 1 e
e e e e





Algorithm: approach 1
1. for every cell in the grid, if it is empty, BFS, else, return 0;
2. For BFS, look at 8 of its neighbours and keep track of the distance.

New algorithm: approach 2 fill up the values along the way
1. make a note of the cells that have stars.
2. When I encounter a star, launch a BFS, if it has already been visited, calculate min of current Distance and it's value. Else, assign current distance.
3. Stop when I encounter another star.

Approach 3: 

BFS from just the stars.

BFS from stars is the best solution.
input:
e * e e
e e e *
e e * e

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

struct cell {
    int one;
    int two;
    int dist;
};

bool isValid(vector<vector<char>> arr, int r, int c) {
    if(r < 0 || r >= arr.size() || c < 0 || c >= arr[0].size())
        return false;
    return true;
}

bool isSafe(int i, int j, vector<vector<char>> arr, vector<vector<int>> result) {
    return arr[i][j] == 'e' && result[i][j] == INT_MAX;
}

void bfs_star(vector<vector<char>> arr, int r, int c, vector<vector<int>> &result, int distance, queue <cell> Q,vector<int> row, vector<int> col) {
    result[r][c] = 0;
    while (!Q.empty()) {
        int x = Q.front().one;
        int y = Q.front().two;
        distance = Q.front().dist;
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int curr_row = x + row[i];
            int curr_col = y + col[i];
            if (isValid(arr, curr_row, curr_col)) {
                if (isSafe(curr_row, curr_col, arr, result)) {
                    result[curr_row][curr_col] = distance + 1;
                    Q.push({curr_row, curr_row, distance + 1});
                }
                else {
                    result[curr_row][curr_col] = min(distance + 1,result[curr_row][curr_col]);
                }
            }
        }
    }
}
vector<vector<int>> calculate_distance(vector<vector<char>> &arr) {
    vector<pair<int,int>> stars;
    int m = arr.size();
    int n = arr[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == '*') {
                stars.push_back(make_pair(i,j));
            }
        }
    }
    queue <pair<int,int>> Q;
    int count = 1;
    vector<vector<int>> result(m,vector<int>(n,INT_MAX));
    for(int i = 0; i < stars.size(); i++) {
        int r = stars[i].first;
        int c = stars[i].second;
        int distance = 0;
        queue <cell> Q;
        Q.push({r,c,distance});
        vector<int> row = {0,-1,-1,-1,0,1,1,1};
        vector<int> col = {-1,-1,0,1,1,1,0,-1};
        cout << "star " << count << " result : " << endl;
        bfs_star(arr,r,c,result,distance,Q,row,col);
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[0].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        count++;
    }
    return result;
}


int main() {
    vector <vector< char>> arr = {{'e','*','e','e'}, {'e','e','e','*'}, {'e','e','*','e'}};
    int m = arr.size();
    int n = arr[0].size();
    cout << "Input : " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> result = calculate_distance(arr);

    cout << "Output : " << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
