/*
Complete the function findCriticalConnections
The function takes integers noOfServers, noOfConnections and 2D integer array as parameters.
Returns a 2D integer array.
*/

void dfs(int u, int &time, vector<int> &visited, 
    vector<int> &discovery_time, vector<int> &lowest_time, vector<int> &parent,
    vector<vector<int>> &adj, vector<vector<int>> &result) {
    visited[u] = 1;
    discovery_time[u] = lowest_time[u] = time++;

    for(int v: adj[u]) {
        if (visited[v] == -1) {
            parent[v] = u;
            dfs(v, time, visited, discovery_time, lowest_time, parent, adj, result);
            lowest_time[u] = min(lowest_time[u], lowest_time[v]);
            if (lowest_time[v] > discovery_time[u]) {
                result.push_back({u, v});
            }
        } 
        else if (v != parent[u]) {
            lowest_time[u] = min(lowest_time[u], discovery_time[v]);
        }
    }
}

vector<vector<int>> findCriticalConnections(int noOfServers, int noOfConnections, vector<vector<int>> connections) {
    vector<vector<int>> result;
    
    vector<vector<int>> adj_matrix(noOfServers);
    
    vector<int> discovery_time(noOfServers);
    vector<int> lowest_time(noOfServers, INT_MAX);
    vector<int> visited(noOfServers, -1);
    vector<int> parent(noOfServers);
    
    for(auto connection : connections){
        int a = connection[0];
        int b = connection[1];
        adj_matrix[a].emplace_back(b);
        adj_matrix[b].emplace_back(a);
    }
    
    int time = 0;
    for(int server = 0; server < noOfServers; server++){
        if(visited[server] == -1)
            dfs(server, time, visited, discovery_time, lowest_time, parent, adj_matrix, result);    
    }
    
    if(result.empty()){
        result.push_back({-1, -1});
    }
    
    return result;
    
}



