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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        deque<TreeNode*> reverse_q;
        q.emplace(root);
        reverse_q.emplace_back(root);
        bool b = true;
        vector<vector<int>> ans;
        while(!q.empty()) {
            ans.emplace_back();
            while(!reverse_q.empty()) {
                ans.back().emplace_back(b ? reverse_q.front()->val : reverse_q.back()->val);
                if(b) reverse_q.pop_front();
                else reverse_q.pop_back();
            }
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                if(node->left) {
                    q.emplace(node->left);
                    reverse_q.emplace_back(node->left);   
                }
                if(node->right) {
                    q.emplace(node->right);
                    reverse_q.emplace_back(node->right);
                }
            }
            b = !b;
        }
        return ans;
    }
};