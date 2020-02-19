TreeNode* build_balanced_bst_helper(vector<int>& a, int start, int end) 
{
    if(start > end)
        return NULL;
    else {
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(a[mid]);
        node->left_ptr = build_balanced_bst_helper(a,start,mid-1);
        node->right_ptr = build_balanced_bst_helper(a,mid+1,end);
        return node;
    }
}

TreeNode * build_balanced_bst(vector<int> a)
{
    if(a.size() == 0)
        return NULL;
	TreeNode* root = build_balanced_bst_helper(a,0,a.size()-1);
	return root;
}
