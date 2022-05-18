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
    int ans{0};
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        ans = max(ans, left+right);
        return 1+max(left,right);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};