// A C++ program to print topological sorting of a DAG 
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Class to represent a graph 
class Graph {
    int V; // No. of vertices'

    // Pointer to an array containing adjacency listsList
    unordered_map<int,vector<int>> adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack);

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();

    void printEdge();
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int v, int w)
{
    if(adj.find(v) == adj.end()) {
        vector<int> temp = {w};
        adj.insert(make_pair(v,temp));
    }
    else {
        adj[v].push_back(w);
    }
     // Add w to v’s list.
}

void Graph::printEdge() {
    for(unordered_map<int,vector<int>>::iterator it = adj.begin(); it != adj.end(); ++it) {
        for(vector<int>::iterator j = it->second.begin(); j != it->second.end(); j++) {
            cout << it->first << " : " << *j << endl;
        }
    }
}
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, vector<bool> &visited,
                                stack<int>& Stack)
{

    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (visited[*it] != true) {
            topologicalSortUtil(*it, visited, Stack);
        }
    }

    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    vector<bool> visited(V+1,false);
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << ", ";
        Stack.pop();
    }
}

// Driver program to test above functions 
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    /*
     * 5: 2,0
     * 4: 0,1
     * 2: 3
     * 3: 1
     * */
    g.printEdge();

    cout << " Following is a Topological Sort of the given graph n : ";
    g.topologicalSort();

    return 0;
} 
