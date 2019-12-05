#include <iostream>

//inorder
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): data(v),left(NULL),right(NULL) {}
};

/*      5
    6       7
 3    10 11     19

 inorder : 3 6 10 5 11 7 19
 preorder : 5 6 3 10 7 11 19
 postOrder : 3 10 6 11 19 7 5
*/

/*void inOrderTraversal(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}*/

/*
void preOrderTraversal(TreeNode* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
*/

void postOrderTraversal(TreeNode* root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}
int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* leftR = new TreeNode(6);
    root->left = leftR;
    TreeNode* rightR = new TreeNode(7);
    root->right = rightR;
    leftR->left = new TreeNode(3);
    leftR->right = new TreeNode(10);
    rightR->left = new TreeNode(11);
    rightR->right = new TreeNode(19);
    postOrderTraversal(root);
    return 0;
}
