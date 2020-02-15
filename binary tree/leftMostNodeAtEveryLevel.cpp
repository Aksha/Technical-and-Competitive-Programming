//Print the left most node at every level or left view of a binary tree

// could be a binary or N-ary tree.

/*
Input :
    5
    /\
  7   8
   \   \
    6   2
       /
      1
Output: [5,7,6,1]

Time complexity : O(n) where n = number of nodes; space: O(n) - the queue can hold up to n nodes worst case N - ary tree and many nodes in one level
*/

#include <iostream>
#include <queue>

Node {
  int val;
  Node* left;
  Node* right;
  Node () {}
  Node(int v) : val(v), left(NULL), right(NULL) {}
}

//use BFS - every time you see a new level , print the first node. Alternatively, You can do a level order traversal and print the node in the 0th index.

void printLeftMostAtEv  eryLevel(Node n) {
    queue<Node*> q;
    q.push(n);
    while(!q.empty()) {
      int size = q.size();
      bool printed = false;
      while(size-- > 0) {
        Node newNode = q.pop();
        if(!printed) {
          cout << newNode->val << endl;
          printed = true;
        }
        if(newNode->left)
            q.push(newNode->left);
        if(newNode->right)
            q.push(newNode->right);
      }
    }
    
  
}
