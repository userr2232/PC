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
    int ans;
    
    void dfs(TreeNode* root, int k, int&& count = 0) {
        if(root == nullptr || count > k) return;
        dfs(root->left, k, forward<int>(count));
        if(++count == k) {
            ans = root->val;
            return;
        }
        dfs(root->right, k, forward<int>(count));
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};