/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        if(left < 0 || right < 0 || abs(left - right) > 1) return -1;
        return 1+max(left, right);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        auto depth = maxDepth(root);
        return depth >= 0;
    }
};