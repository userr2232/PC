class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(!root) return vector<int>(0);
        q.push({root, 0});
        vector<int> answer;
        while(!q.empty()) {
            auto [cur, cur_level] = q.front();
            q.pop();
            if(!cur) continue;
            if(cur->left) q.push({cur->left, cur_level+1});
            if(cur->right) q.push({cur->right, cur_level+1});
            if(!q.empty()) {
                auto [next, next_level] = q.front();
                if(next_level > cur_level) {
                    answer.push_back(cur->val);
                }
                else continue;
            }
            else {
                answer.push_back(cur->val);
            }
        }
        return answer;
    }
};