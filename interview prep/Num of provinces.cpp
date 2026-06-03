https://leetcode.com/problems/number-of-provinces/ 


/*class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Use the grid as AM. 
        // {0, {1}}
        // {1, {0}}
        // {2, {}}

        //two dimensional array
    //     for(i = 0; i < size of array, i++) {
    //         if(node i is unvisited) {
    //             DFS (on i)
    //             count of the provinces ++;
    //         }
    //     }
    //     return count of provinces
    // }

    // dfs(i, matrix) {
    //     mark i as visited
    //     for(j = 0; j < matrix[i].sizE(); j++) {
    //     }
    // }


    /*
        0, 1 pop 0
        q is empty then I can increase province count by 1
        next row,
        next row, 
        2 
    

    A - B. {A, {B,C}} , {B, {A}}
      \ 
       C

       D {D, {}}

    
};
*/

/*
[[1,1,0],
[1,1,0],
[0,0,1]]

isConnected[0][0] = 1
isConnected[0][1] = 1
isConnected[1][0] = 1

*/

class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
