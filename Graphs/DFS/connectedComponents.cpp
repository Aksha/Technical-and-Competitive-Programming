/*Find the number of connected components in the graph

I/P:
1 --- 2   5
|  \  |   |    7
|   \ |   |
3 --- 4   6 

O/P: 3
*/

void dfs(int vertex, int components) {
  visited[vertex] = components;
  for(int j = 0; j < AL[vertex].size(); j++) {
      dfs(j,component);
  }
}

void connectedComponents() {
  int components = 0;
  for(int i = 0; i < vertices.size(); i++) {
    if(color(vertices[i] == 0) {
      components++;
      dfs(vertices[i],components);
    }
  }
  return components;
}
