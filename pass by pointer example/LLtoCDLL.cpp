/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/
/*
    Complete the function below
*/


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

