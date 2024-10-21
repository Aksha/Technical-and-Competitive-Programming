#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }

private:
    int dfs(TreeNode* node, int& max_sum) {
        if (!node) return 0;

        int left = dfs(node->left, max_sum);
        int right = dfs(node->right, max_sum);

        if (!node->left && !node->right) return node->val;

        if (node->left && node->right) {
            max_sum = std::max(max_sum, left + right + node->val);
        }

        return node->val + std::max(left, right);
    }
};

// Function to delete the tree nodes
void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Example usage
int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxPathSum(root);
    std::cout << "Maximum path sum between two leaf nodes: " << result << std::endl;

    // Clean up memory
    deleteTree(root); // Delete the tree nodes

    return 0;
}
