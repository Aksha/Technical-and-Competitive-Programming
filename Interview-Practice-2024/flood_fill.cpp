C++ BFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int startColor = image[sr][sc];
        if (startColor == newColor) return image;
        int e[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        image[sr][sc] = newColor;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = r + e[k][0];
                int y = c + e[k][1];
                if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == startColor) {
                    image[x][y] = newColor;
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    }
};

C++ DFS:
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int i, int j, int c0, int c1) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != c0) return;
        image[i][j] = c1;
        dfs(image, i, j - 1, c0, c1);
        dfs(image, i, j + 1, c0, c1);
        dfs(image, i - 1, j, c0, c1);
        dfs(image, i + 1, j, c0, c1);
    }
};
