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
    
    int dfs(TreeNode* current) {
        if(!current) return 0;
        int l{0}, r{0};
        if(current->left) l = dfs(current->left);
        if(current->right) r = dfs(current->right);
        ans += abs(l) + abs(r);
        return l + r + current->val - 1;
    }
    
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};