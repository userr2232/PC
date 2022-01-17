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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.emplace(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                if(cur->left) q.emplace(cur->left);
                if(cur->right) q.emplace(cur->right);
                if(sz == 0) ans.emplace_back(cur->val);
            }
        }
        return ans;
    }
};