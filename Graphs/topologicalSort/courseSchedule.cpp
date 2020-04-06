bool dfs(int cnum, vector<vector<int>>& depList, vector<int>& visited, vector<int>& departure, int& timestamp, vector<int>& topSort) {
    visited[cnum] = 1;
    for (int i = 0; i < depList[cnum].size(); i++) {
        int c = depList[cnum][i];
        if (visited[c] == -1) {
            if (dfs(c, depList, visited, departure, timestamp, topSort))
                return true;
        }
        else {
            if (departure[c] == -1)
                return true;
        }
    }
    departure[cnum] = timestamp++;
    topSort.push_back(cnum);
    return false;
}
vector<int> course_schedule(int n, vector<vector<int>> prerequisites) {
    vector<int> visited(n, -1);
    vector<int> departure(n, -1);
    vector<vector<int>> depList(n);
    vector<int> topSort;
    int timestamp = 0;
    for (int i = 0; i < prerequisites.size(); i++) {
        vector<int> dep = prerequisites[i];
        depList[dep[1]].push_back(dep[0]);
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (dfs(i, depList, visited, departure, timestamp, topSort))
                return {-1};
        }
    }
    reverse(topSort.begin(), topSort.end());
    return topSort;
}
