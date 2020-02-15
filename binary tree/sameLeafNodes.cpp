//Write a program to find out if two trees have the same leaf nodes

/*Idea: Tree Iterator
first tree:

      a                   
     / \
    b   e
   / \
  c   d
  
second tree:
  
      a
     / \
    b   f
   / \   \
  c   d   e */
  
  
//  Solution: 

struct Node {
      int val;
      Node* left;
      Node* right;
      Node(int v) : val(v), left(NULL), right(NULL) {}
}

struct iterator {
      iterator* next();
      bool hasNext();
}

struct leafNodeIterator : iterator {
      leafNodeIterator(Node n) {}
}

//Some magical method for understanding: 

bool isEqualLeafNodes(Node tree1, Node tree2) {
      iterator <Node> it1 = new leafNodeIterator(tree1);
      iterator <Node> it2 = new leafNodeIterator(tree2);
      
      while(it1.hasNext() && it2.hasNext()) {
            Node leaf1 = it1.next();
            Node leaf2 = it2.next();
            if(leaf1.val != leaf2.val) return false;
      }
      return !it1.hasNext() && !it2.hasNext();
}

//Actual Implementation: 
