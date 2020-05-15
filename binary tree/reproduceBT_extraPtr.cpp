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
        extra_pointers.insert(make_pair(root->extra_ptr->value, root->value);
    return newRoot;
}

void reproduceBT_helper_extra(Node* root, Node** newRoot, unordered_map <int,int> extra_pointers) {
    if(root == NULL)
        return;
    int parentValue = 0;
    int childValue = 0;
    if(root->extra_ptr) {
        unordered_map<int,int>::iterator it = extra_pointers.begin();
        if(extra_pointers.find(root->extra_ptr->value) != extra_pointers.end()) {
            parentValue = root->extra_ptr->value;
            childValue = extra_pointers[root->extra_ptr->value];
        }
        Node* node1 = new Node();
        Node* node2 = new Node();
        
        //search for both these values in the newRoot tree
        //node1 = parentValue Node
        //node2 = extra_pointer pointing to this node
        node1->extra_ptr = node2;
    }
    return;
}

Node* reproduceBT(Node* root) {
    unordered_map<int,int> extra_pointers;
    Node* newRoot = reproduceBT_helper(root, extra_pointers);
    reproduceBT_helper_extra(root, &newRoot, extra_pointers);
    return newRoot;
}

int main(){
    Node* root = new Node(7);
    Node* newRoot = reproduceBT(root);
    return 0;
}
