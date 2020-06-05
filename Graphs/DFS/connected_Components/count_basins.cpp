/*
Count Basins

Problem Statement:
You are given a matrix where each number represents altitude of that cell, such that, water flows towards lower altitudes. If a cell’s four neighboring cells all have higher altitudes, we call this cell a sink; water collects in sinks. 

Otherwise, water will flow to the neighboring cell with the lowest altitude. If a cell is not a sink, you may assume it has a unique lowest neighbor and that this will be lower than the cell. 

Cells that drain into the same sink – directly or indirectly – are said to be part of the same basin. Your challenge is to partition the map into basins. Your code should output the sizes of the basins, in non-decreasing order.
Input/Output Format For The Function:

Input Format:
There will be only one argument matrix denoting the matrix of size row_count * col_count, with the altitude represented as int in each cell.

Output Format:
Return an array of integers, denoting the sizes of basins, in non-decreasing order.

Input/Output Format For The Custom Input:
Input Format:

The first line of the input contains a number row_count, denoting the number of rows of the matrix. The second line of the input contains a number col_count, denoting the number of columns of the matrix. Next row_count lines, contains col_count numbers denoting matrix[i][j] where 0<=i<row_count and 0<=j<col_count.
For row_count=3, col_count=3 and matrix = [ [1, 5, 2], [2, 4, 7], [3, 6, 9]]

3
3
1 5 2
2 4 7
3 6 9

Output Format:
The output contains an array of numbers basin_sizes. Values of the basin_sizes array will be represented as one on a line.
For row_count=3, col_count=3 and matrix = [ [1, 5, 2], [2, 4, 7], [3, 6, 9]], output will be:

2
7

Constraints:
1 <= row_count * col_count <= 1000000.
0 <= matrix[i][j] <= 1000000 where 0<=i<row_count, 0<=j<col_count.
Sample Test Cases:
Sample Input:
3
3
1 5 2
2 4 7
3 6 9
Sample Output:
2
7
Explanation:
The basins, labeled with A’s and B’s, are:

A A B
A A B
A A A

Every cell labeled with A will sink at (0, 0), whereas B will sink at (0, 2).
*/


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;


typedef pair<int,int> one_pair;

struct pair_hash
{
    template <class T1, class T2>
    int operator() (const pair<T1, T2> &p) const
    {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second);
    }
};

bool valid(vector<vector<int>> matrix,int row, int col) {
    if(row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size())
        return true;
    return false;
}


vector<vector<int>> count_basins(vector<vector<int>> matrix) {
    unordered_map<one_pair,int,pair_hash> hmap;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> not_visited(m,vector<int>(n,-1));
    vector<vector<int>> basins;
    for(int i = 0 ; i < m; i++) {
        for(int j = 0; j < n; j++) {
            pair<int,int> temp(i,j);
            hmap.insert(make_pair(temp, matrix[i][j]));
            cout  << hmap[{i,j}] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int connectedComponents = 0;
    vector<int> r{0,0,-1,1};
    vector<int> c{-1,1,0,0};
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (not_visited[i][j] == -1) {
                int minimum = matrix[i][j];
                int x = i;
                int y = j;
                for (int k = 0; k < 4; k++) {
                    int row = i + r[k];
                    int col = j + c[k];
                    if (valid(matrix, row, col)) {
                        if (minimum >= matrix[row][col]) {
                            minimum = matrix[row][col];
                            x = row;
                            y = col;
                        }
                    }
                }
                if (not_visited[x][y] != -1) {
                    not_visited[i][j] = not_visited[x][y];
                } else {
                    not_visited[x][y] = connectedComponents;
                    not_visited[i][j] = not_visited[x][y];
                    connectedComponents++;
                }
            }
        }
    }
    return not_visited;
}

void count_sort(vector <int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]-min]++;
    }

    for(int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    for(int i = arr.size()-1; i >= 0; i--) {
        output[ count[arr[i]-min] -1 ] = arr[i];
        count[arr[i]-min]--;
    }

    for(int i=0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<vector<int>> matrix = {{2,1,3}, {2,3,4}, {3,2,1}};
    vector<vector<int>> basins = count_basins(matrix);
    int m = basins.size();
    int n = basins[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << basins[i][j] << " ";
        }
        cout << endl;
    }
    int total = m * n;
    vector<int> basin_sizes(total, 0);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            basin_sizes[basins[i][j]]++;
        }
    }

    count_sort(basin_sizes);

    for(int i = 0; i < basin_sizes.size(); i++) {
        if(basin_sizes[i] == 0)
            continue;
        else
            cout << basin_sizes[i] << endl;
    }
    return 0;
}
