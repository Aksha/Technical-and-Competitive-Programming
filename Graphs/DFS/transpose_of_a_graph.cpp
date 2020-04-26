/*
Given A Graph, Build A New One With Reversed Edges

Given a strongly connected directed graph, build a new graph with the same number of nodes but every edge reversed. This is also called transposing a graph

Input Parameters: Function has one argument pointing to a node of the given graph.
Output: Return any node of the new graph.
*/

//Solution
/*
    For your reference:

    struct Node
    {
    	int val;
    	vector<Node *> neighbours;
    	Node(int _val = 0)
    	{
    		val = _val;
    		neighbours.clear();
    	}
    };
    
    use an unordered map. 
    You need to keep track of all the neighbours that are accessing a given node. Only then you'll be able to reverse the edges. Use an unordered_map<int, Node*> to keep track of it.
    
    1. Use an unordered_map<int, Node*> to keep track of the node that are accessing the current node.
    2. The new graph is built with this given node has all of the nodes that are accessing it as it's neighbours.
*/

Node *build_other_graph_helper( Node *root, unordered_map<Node*, Node*> &mapping ) {
    if( !root ) return root;
    if( mapping.count( root ) > 0 ) return mapping[ root ];
    Node* root2 = new Node( root->val );
    mapping[ root ] = root2;
    if( root->neighbours.empty() ) return root2;
    for( int i=0; i<root->neighbours.size(); ++i ) { 
        Node *tmp = build_other_graph_helper( root->neighbours[i], mapping ); 
        tmp->neighbours.push_back( root2 ); 
    } 
    return root2;    
}

Node *build_other_graph( Node *root ) {
    unordered_map<Node*, Node*> mapping;
    return build_other_graph_helper( root, mapping );
} 

//Easy to understand solution:
void dfs(Node *node, unordered_map<int, Node *> &reversed)
{	
	/*
	Note that we are passing reversed by reference, either use passing by reference or use global 
	variable. 
	*/
	// First create new node.
	reversed[node->val] = new Node(node->val);
	int n = node->neighbours.size();
	// Visit all the neighbours.
	for (int i = 0; i < n; i++)
	{
		// If node is not visited then first visit it.
		if (reversed.find(node->neighbours[i]->val) == reversed.end())
		{
			dfs(node->neighbours[i], reversed);
		}
		// Add the reverse edge. 
		reversed[node->neighbours[i]->val]->neighbours.push_back(reversed[node->val]);
	}
}

Node *build_other_graph(Node *node)
{
	/*
	In constraints we are given that each node contains distinct values, so we can keep track of 
	node address using that value. {value : node}.
	*/
	unordered_map<int, Node *> reversed;
	// Build the graph.
	dfs(node, reversed);
	// Return any node of the new graph. 
	return reversed.begin()->second;
}
