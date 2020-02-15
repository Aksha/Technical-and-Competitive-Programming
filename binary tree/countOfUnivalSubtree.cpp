// Find the count of Unival Subtrees:

// Solution: 

Node {
  int val;
  Node* left;
  Node* right;
  Node(char x) : c(x), left(NULL), right(NULL) {}
}

//global variable or class
Class counter { int count; }

bool countSVT(Node n , Counter c) {
  if(n == NULL) return true;
  bool isLeft = countSVT(n->left,c);
  bool isRight = countSVT(n->right,c);
  if(!isleft || !isright)
    return false;
  if(n->left != NULL && n->left->val != n->val) 
    return false;
  if(n->right != NULL && n->right->val != n->val)
    return false;
  c.counter++;
  return true;
}


int count SingleValueTree(Node n) {
  return countSVT(Node n, Counter c); 
}
