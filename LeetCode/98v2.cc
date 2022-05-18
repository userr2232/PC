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
    static const long INF = 3e9;
    
    bool isValidBST(TreeNode* root, long min_val, long max_val) {
        if(root == nullptr) return true;
        if(root->val >= min_val || root->val <= max_val) return false;
        return isValidBST(root->left, root->val, max_val) && isValidBST(root->right, min_val, root->val);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return isValidBST(root->left, root->val, -INF) && isValidBST(root->right, INF, root->val);
    }
};