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
    int diameter{0};
    
    int dfs_helper(TreeNode* cur) {
        if(!cur) return 0;
        int leftpath = dfs_helper(cur->left);
        int rightpath = dfs_helper(cur->right);
        diameter = max(diameter, leftpath+rightpath);
        return max(leftpath, rightpath) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs_helper(root);
        return diameter;
    }
};