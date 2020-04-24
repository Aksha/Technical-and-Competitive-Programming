
Given A Graph, Build A New One With Reversed Edges
Given a strongly connected directed graph, build a new graph with the same number of nodes but every edge reversed. This is also called transposing a graph.


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
    
    1->2        2->1
    2->3   =    3->2
    3->1        1->3
    
    There are two parts to this problem.
    1. Create a clone graph.
    2. Reverse edges of clone graph.
    // Good reference: https://oj.interviewkickstart.com/view_top_submission/11651/39/15182/
*/

//incorrect solution..... Fix it
Node* build_other_graph_helper(Node* root, unordered_map<Node*, Node*> mapping) {
    if(root == NULL)
        return root;
    int n = root->neighbours.size();
    //Node* root2 = new Node(root->val);
    for(int i = 0; i < n; i++) {
        if(mapping.find(root[i]->neighbours->val) == mapping.end()) {
            build_other_graph_helper(root,mapping);
            Node* temp = new Node(root);
            vector<Node*> start = {temp};
            mapping.insert(make_pair(root->neigbours[i]->val,temp));
        }
        else {
            Node* temp = new Node(root);
            mapping[root->neigbours[i]->val].push_back(temp);
        }
    }
    return root;
}

Node *build_other_graph( Node *root ) {
    unordered_map<Node*, Node*> mapping;
    return build_other_graph_helper( root, mapping );
} 

