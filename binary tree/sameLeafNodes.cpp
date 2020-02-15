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
  
  
/*  Solution: Time complexity : O(m+n) worst case where m is the number of nodes in Tree1 and n is the number of nodes in Tree2
A Simple Solution is traverse first tree and store leaves from left and right in an array. Then traverse other tree and store leaves in another array. Finally compare two arrays. If both arrays are same, then return true.

The above solution requires O(m+n) extra space where m and n are nodes in first and second tree respectively.

How to check with O(h1 + h2) space?
The idea is use iterative traversal. Traverse both trees simultaneously, look for a leaf node in both trees and compare the found leaves. All leaves must match.
*/

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
      stack S;
      leafNodeIterator(Node n) {
      	S.push(n);
      }
      bool hasNext() {
      	if(currentLeafNode != NULL)
		return true;
	while(!s.empty()) {
		.......
	}
      }
      
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
// C++ code to check if leaf traversals 
// of two Binary Trees are same or not. 
#include<bits/stdc++.h> 
using namespace std; 

// Binary Tree Node 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

// Returns new Node with data as 
// input to below function. 
Node* newNode(int d) 
{ 
	Node* temp = new Node; 
	temp->data = d; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 

// checks if a given node is leaf or not. 
bool isLeaf(Node* root) 
{ 
	if(root == NULL) 
		return false; 
	if(!root->left && !root->right) 
		return true; 
	return false; 
} 

// iterative function. 
// returns true if leaf traversals 
// are same, else false. 
bool isSame(Node* root1, Node* root2) 
{ 
	stack<Node*> s1; 
	stack<Node*> s2; 
	
	//push root1 to empty stack s1. 
	s1.push(root1); 
	
	//push root2 to empty stack s2. 
	s2.push(root2); 
	
	// loop until either of stacks are non-empty. 
	while(!s1.empty() || !s2.empty()) 
	{ 
		// this means one of the stacks has 
		// extra leaves, hence return false. 
		if(s1.empty() || s2.empty()) 
			return false; 
			
		Node* temp1 = s1.top(); 
		s1.pop(); 
		while(temp1 != NULL && !isLeaf(temp1)) 
		{ 
			// Push right child if exists 
			if(temp1->right) 
				s1.push(temp1->right); 
				
			// Push left child if exists 
			if(temp1->left) 
				s1.push(temp1->left); 
				
			// Note that right child(if exists) 
			// is pushed before left child(if exists). 
			temp1 = s1.top(); 
			s1.pop(); 
		} 
		
		Node* temp2 = s2.top(); 
		s2.pop(); 
		while(temp2 != NULL && !isLeaf(temp2)) 
		{ 
			// Push right child if exists 
			if(temp2->right) 
				s2.push(temp2->right); 
				
			// Push left child if exists 
			if(temp2->left) 
				s2.push(temp2->left); 
			temp2 = s2.top(); 
			s2.pop(); 
		} 
		
		if(!temp1 && temp2) 
			return false; 
		if(temp1 && !temp2) 
			return false; 
		if(temp1 && temp2) 
		{ 
			return temp1->data == temp2->data; 
		} 
	} 
	
	// all leaves are matched 
	return true; 
} 

// Driver Code 
int main() 
{ 
	Node* root1 = newNode(1); 
	root1->left = newNode(2); 
	root1->right = newNode(3); 
	root1->left->left = newNode(4); 
	root1->right->left = newNode(6); 
	root1->right->right = newNode(7); 
	
	Node* root2 = newNode(0); 
	root2->left = newNode(1); 
	root2->right = newNode(5); 
	root2->left->right = newNode(4); 
	root2->right->left = newNode(6); 
	root2->right->right = newNode(7); 
	
	if(isSame(root1, root2)) 
		cout << "Same"; 
	else
		cout << "Not Same"; 
	return 0; 
} 
