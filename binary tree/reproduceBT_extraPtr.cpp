// Compiled with: g++ -Wall -std=c++14 -pthread


/*
        7
       / \
      5---8  7--->6 , 6--->7, 5--->8
     / \
    6   1
    
    unordered_map<int, Node*> extra_ptr;
    [5->8*,
    7->6*,
    6->7*]
  
*/
/*
        7'
       / \
      5'  8' 
     / \
    6'   1'
    
    
*/


#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int value;
    Node* left_ptr;
    Node* right_ptr;
    Node* extra_ptr;
    Node(int val) : value (val), left_ptr(NULL), right_ptr(NULL) {}
    Node() {}
};

Node* reproduceBT_helper(Node* root, unordered_map <int,int> extra_pointers) {
    Node* newRoot;
    if(root == NULL)
        return NULL;
    newRoot->value = root->value;
    if(root->left_ptr)
        newRoot->left_ptr = reproduceBT_helper(root->left_ptr, extra_pointers);
    if(root->right_ptr)
        newRoot->right_ptr = reproduceBT_helper(root->right_ptr, extra_pointers);
    if(root->extra_ptr)
        extra_pointers.insert(make_pair(root->extra_ptr->value, root->value));
    return newRoot;
}

void searchParentAndChild(int parentValue, int childValue, Node** root1) {
    Node* node1 = new Node();
    Node* node2 = new Node();
    if((*root1)->value == parentValue)
        node1 = (*root1);
    if((*root1)->value == childValue && parentValue != childValue)
        node2 = (*root1);
    if(!node1 && !node2) {
        node1->extra_ptr = node2;
        Node* node1 = new Node();
        Node* node2 = new Node();
    }
    if((*root1)->left_ptr) {
        (*root1) = (*root1)->left_ptr;
        searchParentAndChild(parentValue, childValue, root1);
    }
    if((*root1)->right_ptr) {
        (*root1) = (*root1)->right_ptr;
        searchParentAndChild(parentValue, childValue, root1);
    }
}

Node* reproduceBT_helper_extra(Node* root, Node* root1, unordered_map <int,int> extra_pointers) {
    if(root == NULL)
        return NULL;
    int parentValue = 0;
    int childValue = 0;
    if(root->extra_ptr) {
        unordered_map<int,int>::iterator it = extra_pointers.begin();
        if(extra_pointers.find(root->extra_ptr->value) != extra_pointers.end()) {
            parentValue = root->extra_ptr->value;
            childValue = extra_pointers[root->extra_ptr->value];
        }
        searchParentAndChild(parentValue, childValue, &root1);
    }
    if(root->left_ptr)
        reproduceBT_helper_extra(root->left_ptr, root1, extra_pointers);
    if(root->right_ptr)
        reproduceBT_helper_extra(root->right_ptr, root1, extra_pointers);
    return root1;
}

Node* reproduceBT(Node* root) {
    unordered_map<int,int> extra_pointers;
    Node* root1 = reproduceBT_helper(root, extra_pointers);
    Node* newRoot = reproduceBT_helper_extra(root, root1, extra_pointers);
    return newRoot;
}

int main(){
    Node* root = new Node(7);
    root->left_ptr = new Node(5);
    root->right_ptr = new Node(8);
    root->left_ptr->left_ptr = new Node(6);
    root->left_ptr->right_ptr = new Node(1);
    root->left_ptr->extra_ptr = root->right_ptr;
    root->extra_ptr = root->left_ptr->left_ptr;
    root->left_ptr->left_ptr->extra_ptr = root;
    Node* newRoot = reproduceBT(root);
    cout << "--------TESTING--------" << endl;
    cout << newRoot->value << endl;
    cout << newRoot->extra_ptr->value <<endl;
    return 0;
}


//----------------------------------ANOTHER SOLUTION ALONG THE SAME LINES--------------------------------------------------------------------

// A hashmap based C++ program to clone a binary 
// tree with random pointers 
#include<iostream> 
#include<unordered_map> 
using namespace std; 

/* A binary tree node has data, pointer to left child, 
	a pointer to right child and a pointer to 
	random node*/
struct Node 
{ 
	int key; 
	struct Node* left, *right, *random; 
}; 

/* Helper function that allocates a new Node with the 
given data and NULL left, right and random pointers. */
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->random = temp->right = temp->left = NULL; 
	return (temp); 
} 

/* Given a binary tree, print its Nodes in inorder*/
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* First recur on left sutree */
	printInorder(node->left); 

	/* then print data of Node and its random */
	cout << "[" << node->key << " "; 
	if (node->random == NULL) 
		cout << "NULL], "; 
	else
		cout << node->random->key << "], "; 

	/* now recur on right subtree */
	printInorder(node->right); 
} 

// This function creates clone by copying key and left and right pointers 
// This function also stores mapping from given tree node to clone. 
Node* copyLeftRightNode(Node* treeNode, unordered_map<Node *, Node *> &mymap) 
{ 
	if (treeNode == NULL) 
		return NULL; 
	Node* cloneNode = newNode(treeNode->key); 
	mymap[treeNode] = cloneNode; 
	cloneNode->left = copyLeftRightNode(treeNode->left, mymap); 
	cloneNode->right = copyLeftRightNode(treeNode->right, mymap); 
	return cloneNode; 
} 

// This function copies random node by using the hashmap built by 
// copyLeftRightNode() 
void copyRandom(Node* treeNode, Node* cloneNode, unordered_map<Node *, Node *> &mymap) 
{ 
	if (cloneNode == NULL) 
		return; 
	cloneNode->random = mymap[treeNode->random]; 
	copyRandom(treeNode->left, cloneNode->left, mymap); 
	copyRandom(treeNode->right, cloneNode->right, mymap); 
} 

// This function makes the clone of given tree. It mainly uses 
// copyLeftRightNode() and copyRandom() 
Node* cloneTree(Node* tree) 
{ 
	if (tree == NULL) 
		return NULL; 
	unordered_map<Node *, Node *> mymap; 
	Node* newTree = copyLeftRightNode(tree, mymap); 
	copyRandom(tree, newTree, mymap); 
	return newTree; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	//Test No 1 
	Node *tree = newNode(1); 
	tree->left = newNode(2); 
	tree->right = newNode(3); 
	tree->left->left = newNode(4); 
	tree->left->right = newNode(5); 
	tree->random = tree->left->right; 
	tree->left->left->random = tree; 
	tree->left->right->random = tree->right; 

	// Test No 2 
	// tree = NULL; 

	// Test No 3 
	// tree = newNode(1); 

	// Test No 4 
	/* tree = newNode(1); 
		tree->left = newNode(2); 
		tree->right = newNode(3); 
		tree->random = tree->right; 
		tree->left->random = tree; 
	*/

	cout << "Inorder traversal of original binary tree is: \n"; 
	printInorder(tree); 

	Node *clone = cloneTree(tree); 

	cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
	printInorder(clone); 

	return 0; 
} 
