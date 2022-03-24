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
    typedef pair<int,int> coords;
    map<coords,multiset<int>> m;
    
    void dfs(TreeNode* current, int r = 0, int c = 0) {
        if(current == nullptr) return;
        m[{c,r}].emplace(current->val);
        dfs(current->left, r+1, c-1);
        dfs(current->right, r+1, c+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root);
        vector<vector<int>> ans;
        int prev_col;
        for(auto [coords, s] : m) {
            auto [col, _] = coords;
            if(ans.empty() || prev_col != col) ans.emplace_back(), prev_col = col;
            for(auto x : s) ans.back().emplace_back(x);
        }
        return ans;
    }
};