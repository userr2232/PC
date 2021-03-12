class Solution {
public:
    int maxx = -1e9;
    int max_gain(TreeNode* current) {
        if(!current) return 0;
        auto left_max = max(max_gain(current->left), 0);
        auto right_max = max(max_gain(current->right), 0);
        maxx = max(maxx, current->val + left_max + right_max);
        return current->val + max(left_max, right_max);
    }
    
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return maxx;
    }
};