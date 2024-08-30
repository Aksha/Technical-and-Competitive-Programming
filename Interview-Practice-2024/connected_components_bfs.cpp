#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> build_adj_list(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> list;
        for(int i = 0; i < edges.size(); i++) {
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        return list;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
//using BFS
//build adjacency list using the edges
//take the first vertex
//if not visited, put it in Q
//access top of Q and check for all its children. iF not visited, add it to visited list and put it in the Queue.

        unordered_map<int, vector<int>> adj_list = build_adj_list(edges);
        for(auto it : adj_list) {
            cout << it.first <<  "->";
            vector <int> temp = it.second;
            for(auto i : temp) {
                cout << i << "-->";
            }
            cout << endl;
        }
        unordered_set<int> visited;
        queue <int> Q;
        int count = 0;
        //0->1, 1->2, 2->3

        //0->1
        //1->0->2
        //2->1->3
        //3->2
        //4->5
        //5->4
        for(int i = 0; i < n; i++) {
            if(visited.find(i) == visited.end()) {
                Q.push(i);
                visited.insert(i);
                count++;
                while(!Q.empty()) {
                    int curr = Q.front();
                    Q.pop();
                    for(int j = 0; j < adj_list[curr].size(); j++) {
                        if (visited.find(adj_list[curr][j]) == visited.end()) {
                            visited.insert(adj_list[curr][j]);
                            Q.push(adj_list[curr][j]);
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    int n=6;
    vector<vector<int>> edges={{0,1}, {1,2}, {2,3}, {4,5}};
    Solution s;
    int result = s.countComponents(n,edges);
    cout << "the number of connected components in the graph are :" << result << endl;
    return 0;
}
