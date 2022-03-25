/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* successor{nullptr};
    bool found{false};
    
    void dfs_helper(TreeNode* current, TreeNode* p) {
        if(current == nullptr) return;
        dfs_helper(current->left, p);
        if(found) found = false, successor = current;
        if(current == p) found = true;
        dfs_helper(current->right, p);
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs_helper(root, p);
        return successor;
    }
};