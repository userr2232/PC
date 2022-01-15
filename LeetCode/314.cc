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
    void dfs_helper(map<pair<int,int>, vector<int>>& m, TreeNode* cur, int row, int col) {
        if(!cur) return;
        m[{col,row}].emplace_back(cur->val);
        dfs_helper(m, cur->left, row+1, col-1);
        dfs_helper(m, cur->right, row+1, col+1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<pair<int,int>, vector<int>> m;
        dfs_helper(m, root, 0, 0);
        int COL = 1e9;
        vector<vector<int>> ans;
        int i{0};
        for(const auto& [k, v] : m) for(const auto& e : v) {
            const auto& [col, row] = k;
            if(COL == 1e9) COL = col, ans.emplace_back();
            else {
                if(COL != col) {   
                    i++;
                    ans.emplace_back();
                    COL = col;
                }
            }
            ans[i].push_back(e);
        }
        return ans;
    }
};