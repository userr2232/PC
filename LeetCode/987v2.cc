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
    typedef pair<int,int> coord;
    map<coord,multiset<int>> m;
    
    void dfs_helper(TreeNode* cur, int row = 0, int col = 0) {
        if(!cur) return;
        m[{col,row}].emplace(cur->val);
        dfs_helper(cur->left, row+1, col-1);
        dfs_helper(cur->right, row+1, col+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        dfs_helper(root);
        vector<vector<int>> ans(1);
        int i{0}, COL = m.begin()->first.first;
        for(const auto& [coord, v] : m) for(const auto& e : v) {
            const auto& [col, _] = coord;
            if(COL != col) {
                ++i, COL = col;
                ans.emplace_back();
            }
            ans[i].emplace_back(e);
        }
        return ans;
    }
};