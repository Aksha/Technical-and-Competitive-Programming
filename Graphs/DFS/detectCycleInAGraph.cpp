
bool dfs(vector<vector<int>> &graph, vector<int> &visited, int currentNode) {
    for(int i = 0; i<graph[currentNode].size(); ++i) {
        if (visited[graph[currentNode][i]] == -1)
            return true;
        
        if (visited[graph[currentNode][i]] == 0) {
            visited[graph[currentNode][i]] = -1;
            if(dfs(graph, visited, graph[currentNode][i]))
                return true;
            visited[graph[currentNode][i]] = 1;
        }
    }
    return false;
}

bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here
	//Construct adjacency list
	
	vector<vector<int>> graph(N, vector<int>());
	vector<int> visited(N, 0);
	
	for(int i=0; i<edges.size(); ++i) {
	    graph[edges[i][0]].push_back(edges[i][1]);
	}
	
	for(int i=0; i<N; ++i) {
	    if (visited[i] == 0) {
	        visited[i] = -1;
	        if(dfs(graph, visited, i))
	            return true;
	        visited[i] = 1;
	    }
	}
	
	return false;
	
	
}
