void dfs(int source, vector<string>& zombies, vector<bool>&visited){
    visited[source]=true;
    for(int i=0;i<zombies.size();i++)
        if(zombies[source][i]=='1' && visited[i]==false)
        {
            visited[i]=true;
            dfs(i, zombies, visited);
        }
}

int zombieCluster(vector<string> zombies) {
    vector<bool> visited(zombies.size(), false);
    int component=0;
    for(int i=0;i<zombies.size();i++)
        if(visited[i]==false)
        {    
            dfs(i, zombies, visited);
            component++;
        }
    return component;
}
