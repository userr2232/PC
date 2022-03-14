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
    TreeNode* ans{nullptr};
    
    bool dfs_helper(TreeNode* current, TreeNode* p) {
        if(!current) return false;
        if(current == p) return true;
        if(dfs_helper(current->left, p)) {
            if(!ans) ans = current;
            return true;
        }
        return dfs_helper(current->right, p);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right) {
            auto current = p->right;
            while(current->left) {
                current = current->left;
            }
            return current;
        }
        else {
            dfs_helper(root, p);
        }
        return ans;
    }
};