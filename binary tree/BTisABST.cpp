//Given a BT, check if it is a BST or not - check IKweb interview practice problem number 2

bool isBST_helper(TreeNode* root, int minimum, int maximum) {
    if(root == NULL)
        return true;
    if(root->val < minimum || root->val > maximum)
        return false;
    return isBST_helper(root->left_ptr,minimum,root->val) && isBST_helper(root->right_ptr,root->val,maximum);
}

bool isBST(TreeNode* root){
    int minimum = INT_MIN;
    int maximum = INT_MAX;
    return isBST_helper(root,minimum,maximum);

}


//Another way : eliminate all "false" cases. Then by default, the answer is true.
