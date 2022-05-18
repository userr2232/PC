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
    static const int INF = 1e9;
    
    int goodNodes(TreeNode const* root, const int max_val) {
        if(root == nullptr) return 0;
        auto left = goodNodes(root->left, max(max_val, root->val));
        auto right = goodNodes(root->right, max(max_val, root->val));
        return left + right + (max_val <= root->val);
    }
    
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, -INF);
    }
};