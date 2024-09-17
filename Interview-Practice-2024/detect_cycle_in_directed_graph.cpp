
//DAG (directed acyclic graph) - course schedule priblem - topological sort
//How is topological sort achieved? Using DFS.
//How do you detect cycle in a DAG. If we are revisiting a node using a backward edges, then there is a cycle because there is a path from descendant to ancestor.
//Tree edge, forward edge, cross edge and back edge are important edge definitions that I should be aware of.
// HOw to detect a backward edge, if we are visiting a node that has been visited in the past and that node doesn't have a finish time since its descendeant is being explored, we know that it is a backward edge and a cycle exists in Directed graph.
//how to detect a cycle in an undirected graph. If we are revisiting a node that has been visited and its parent is different.



bool dfs_cycle(int curr_node, unordered_map<int, vector<int>> neighbors, int& timestamp, vector<int>& arrival_time, vector<int>& departure_time, vector<bool> visited) {
    visited[curr_node] = 1;
    arrival_time[curr_node] = timestamp++;
    for(int i = 0; i < neighbors[curr_node].size(); i++) {
        if(!visited[neighbors[curr_node][i]]) { //not visited
            if(dfs_cycle(neighbors[curr_node][i], neighbors, timestamp, arrival_time, departure_time, visited)) {
                return true;
            }
        }
        else { //visited
            if(departure_time[curr_node] == 0) {
                return true;
            }
        }
    }
    departure_time[curr_node] = timestamp++;
    return false;
}


bool has_cycle(int number_of_vertices, int number_of_edges, vector<vector<int>> &edges) {
    // Write your code here.
    //how to extract the nodes alone. 
    unordered_map<int, vector<int>> adj_list;
    vector<bool> visited(number_of_vertices, 0);
    for(int i = 0; i < edges.size(); i++) {
        if(adj_list.find(edges[i][0]) == adj_list.end()) {
            vector<int> temp;
            temp.push_back(edges[i][1]);
            adj_list.insert(make_pair(edges[i][0],temp));
        }
        else {
            adj_list[edges[i][0]].push_back(edges[i][1]); //this will ensure {{0, {1,3}, { {1, {3,2}}, {4,{0}}} 
        }
    }
    int timestamp = 0;
    vector<int> arrival_time(number_of_vertices, 0);
    vector<int> departure_time(number_of_vertices, 0);
    for(auto it = adj_list.begin(); it != adj_list.end(); it++) {
        if(!visited[it->first]) {
            if(dfs_cycle(it->first, adj_list, timestamp, arrival_time, departure_time, visited))
                return true;
        }
    }
    return false;
}
