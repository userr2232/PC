class Solution {
public:
    map<int, multiset<pair<int,int>>> mm;
    
    void DFS(TreeNode* cur, int row = 0, int column = 0) {
        if(cur) {
            DFS(cur->left, row + 1, column - 1);
            mm[column].insert({row, cur->val});
            DFS(cur->right, row + 1, column + 1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root);
        vector<vector<int>> v(mm.size());
        int i = 0;
        for(auto [column, vals] : mm) {
            for(auto [_, val] : vals) {
                v[i].push_back(val);
            }
            i++;
        }
        return v;
    }
};