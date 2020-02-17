/*

Print All Paths of a Tree



Problem Statement:



Given a binary tree. Returns all the paths from root to leaf of the tree. Each path will consist of a list of integer values denoting nodes traversed for that path. e.g. for the tree,
sa;
 
 Pic: Refer allPaths.png in this binary tree folder.

Return a list which contains the following paths:

1 2 4

1 2 5

1 3 6

1 3 7



Input/Output Format For The Function:



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



Return a list of integer lists.



Input/Output Format For The Custom Input:



Input Format:

 

→ line number 1: noOfNodes denoting number of nodes of the tree.



→ line number 2: noOfNodes space separated integers denoting the values of the nodes. Please make sure there are no leading or trailing spaces and between two integers there must be a single space.



→ line number 3: rootIndex denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1



→ line number 4: noOfEdges denoting the number of edges of the tree



→ next noOfEdges line: parentNodeIndex<space>childNodeIndex<space>leftOrRightFlag. Here parentNodeIndex and childNodeIndex are the node indexes ranging from 0 to noOfNodes-1. leftOrRightFlag is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.



Output Format:



Space separated integer denoting the node values in a path. If there are K paths, print K lines.



Constraints:



0 <= noOfNodes <= 10^5
noOfEdges = noOfNodes - 1
-10^9 <= values stored in the nodes <= 10^9


Sample Test Case:



Sample Input:



For the function:







For the custom input:



1

5

10 20 30 40 50

0

4

0 1 L

0 2 R

1 3 L

1 4 R



Sample Output:



For the function:



ret = [ [10,20,40], [10,20,50], [10,30] ]



For the custom output:



10 20 40

10 20 50

10 30



Explanation:



There are 3 paths in the tree. 

The leftmost path contains values: 10 -> 20 -> 40

The rightmost path contains values: 10 -> 30

The other path contains values: 10 -> 20 -> 50



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}



Notes:



→ (Order of paths in output does not matter. Hence for sample input,

10 30

10 20 50

10 20 40

will also be considered as correct answer.

Solution:
*/

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/

/*
    Complete the function below
    Input: root of the input tree
    Output: A list of integer lists denoting the node values of the paths of the tree
*/
void allPathsOfABinaryTree_helper(TreeNode* root, vector<int> currentPath, vector<vector<int>>& allPaths){
    if(!root)
        return;
    currentPath.push_back(root->val);
    if(root->left_ptr == NULL && root->right_ptr == NULL) {
        allPaths.push_back(currentPath);
        currentPath.clear();
        return;
    }
    allPathsOfABinaryTree_helper(root->left_ptr,currentPath,allPaths);
    allPathsOfABinaryTree_helper(root->right_ptr,currentPath,allPaths);
    currentPath.pop_back();
    
}

vector<vector<int> > allPathsOfABinaryTree(TreeNode* root){
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    if(root == NULL)
        return allPaths;
    allPathsOfABinaryTree_helper(root, currentPath, allPaths);
    return allPaths;
}

