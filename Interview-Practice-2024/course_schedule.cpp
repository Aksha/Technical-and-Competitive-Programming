

//check if the graph has cycle or not. THis is considered a directed graph given the pre-requisities.
// for every course, map it to all the pre-requsities that need to be taken and create an adj_list.
//check if this has a cycle when not visited. if it has a cycle, return -1
//if not return the stack in which all the variables are getting stored. 


bool dfs_has_cycle(int curr_node, unordered_map<int, vector<int>> neighbors,int &timestamp, vector<int> &arrival_times,vector<int> &departure_times,vector<bool> &visited,vector<int> &top_sort_stack) {
    visited[curr_node] = 1; //0 is set as visited
    arrival_times[curr_node] = timestamp++; //arrival time [0] = 1
    for(int i = 0; i < neighbors[curr_node].size(); i++) { //neighbors[0] = 1,2
        if(!visited[neighbors[curr_node][i]]) {
            if(dfs_has_cycle(neighbors[curr_node][i], neighbors, timestamp, arrival_times, departure_times, visited, top_sort_stack)) {
                return true;
            }
        }
        else {
            if(departure_times[neighbors[curr_node][i]] == 0) {
                return true;
            }
        }
    }
    departure_times[curr_node] = timestamp++;
    top_sort_stack.push_back(curr_node);
    return false;
}

vector<int> course_schedule(int n, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> top_sort_stack = {};
    if(edges.empty()) {
        for(int i = 0; i < n; i++) {
            top_sort_stack.push_back(i);
        } 
        reverse(top_sort_stack.begin(), top_sort_stack.end());
        return top_sort_stack;
    }
    unordered_map<int, vector<int>> adj_list;
    for(int i = 0; i < edges.size(); i++) {
        if(adj_list.find(edges[i][1]) == adj_list.end()) {
            vector<int> temp;
            temp.push_back(edges[i][0]);
            adj_list.insert(make_pair(edges[i][1],temp));
        }
        else {
            adj_list[edges[i][1]].push_back(edges[i][0]); //this will ensure {{0,{1,2}},{1,{3}},{2,{3}}}
        }
    }
    int timestamp = 0;
    vector<int> arrival_times(n,0);
    vector<int> departure_times(n,0);
    vector<bool> visited(n,0);
    for(auto it = adj_list.begin(); it != adj_list.end(); it++) {
        if(!visited[it->first]) {
            if(dfs_has_cycle(it->first,adj_list,timestamp,arrival_times,departure_times,visited,top_sort_stack)) {
                return {-1};
            }
        }
    }
    reverse(top_sort_stack.begin(), top_sort_stack.end());
    return top_sort_stack;
}
