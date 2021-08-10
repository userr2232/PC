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
public:
    int goodNodes(TreeNode* root, int max_val) {
        if(!root) return 0;
        int leftGoodNodes = goodNodes(root->left, max(max_val, root->val));
        int rightGoodNodes = goodNodes(root->right, max(max_val, root->val));
        return leftGoodNodes + rightGoodNodes + (root->val >= max_val ? 1 : 0);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return goodNodes(root->left, root->val) + goodNodes(root->right, root->val) + 1;
    }
};