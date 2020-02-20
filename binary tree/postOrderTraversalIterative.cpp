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
vector<int> postorderTraversal(TreeNode* root){
    /* 
    Approach 1: Intuitive approach.
    0.While root is not null 
    1. push root->right to stack if root->right exist
    2. Push root ndoe to stack. . 
    3. Assign root->left to root.
    4. when root is null;
    5. pop root->left and add its value to output.
    6. compare root->val and root->right->val. 
        a. If they are the same, root->right hasn't been evaluated, so redo steps 1-3 befoer that put root into stack.
        b. If they are the not the same, pop root node and print it. 
    7. do all these operations as long as the stack is not empty. If the stack is empty, quit.
    
    Approach 2: quick hack 
    Push directly root node two times while traversing to the left. While poping if you find stack top() is same as root then go for root->right else print root.
    */
    
    stack <TreeNode*> S;
    vector<int> result;
    while(true) { 
        while(root != NULL) { 
            S.push(root); 
            S.push(root); 
            root = root->left_ptr; 
        } 
        // Check for empty stack 
        if(S.empty()) 
            return result; 
        root = S.top();
        S.pop();
        if(!S.empty() && S.top() == root)
            root = root->right_ptr; 
        else { 
             result.push_back(root->val); 
             root = NULL; 
        } 
    } 
}

