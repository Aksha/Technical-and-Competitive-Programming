/* 
 Given a BST, traverse the tree and create a (circular) doubly linked list in ascending order, returning the head.
*/

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
  if(FL.last == NULL) {
    FL.last = n;
  }
} 

NodeToDLL( Node* root) {
  FirstLast FL;
  toDLL(root,FL);
  FL->last->right = FL->first;
  FL->first->left = FL->last;
  return FL->first;
}
