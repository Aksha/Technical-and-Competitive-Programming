/* 
 Given a BST, traverse the tree and create a (circular) doubly linked list in ascending order, returning the head.
*/

//Right Solution:

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left_ptr;
    TreeNode* right_ptr;
    TreeNode ();
    TreeNode(int v) : val(v), left_ptr(NULL), right_ptr(NULL) {}
};


void toDLL(TreeNode* curr, TreeNode** head, TreeNode** tail) {
    if(curr == NULL)
        return;
    toDLL(curr->left_ptr, head, tail);
    if((*head) == NULL)
        *head = curr;
    if((*tail) == NULL)
        *tail = curr;
    else {
        (*tail)->right_ptr = curr;
        curr->left_ptr = (*tail);
    }
    *tail = curr;
    toDLL(curr->right_ptr, head, tail);
}


TreeNode* BTtoLL(TreeNode* root){
    if(root == NULL)
        return NULL;
    TreeNode* head = NULL;
    TreeNode* tail = NULL;
    toDLL(root, &head, &tail);
    head->left_ptr = tail;
    tail->right_ptr = head;
    return head;
}


int main() {
    TreeNode* root = new TreeNode(4);
    root->left_ptr = new TreeNode(2);
    root->right_ptr = new TreeNode(5);
    root->left_ptr->left_ptr = new TreeNode(1);
    root->left_ptr->right_ptr = new TreeNode(3);
    TreeNode* result = BTtoLL(root);
    cout << result->val << endl;
    return 0;
}

//Wrong Solution:

struct Node {
  int val;
  Node* left;
  Node* right;
}

struct FirstLast: Node {
  Node* first,
  Node* last;
}

void toDLL(Node* n, FirstLast FL) {
  if(n == NULL) return;
  toDLL(n->left, FL);
  if(FL.first == NULL) {
    FL.first = n;
  }
  Node* prev = FL.last;
  if(prev != NULL){
    prev->right = n;
    n->left = prev;
  }
  FL.last = n;
  toDLL(n->right,FL);
} 

NodeToDLL( Node* root) {
  FirstLast FL;
  toDLL(root,FL);
  FL->last->right = FL->first;
  FL->first->left = FL->last;
  return FL->first;
}
