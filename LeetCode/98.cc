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
    tuple<bool,int, int> isValid(TreeNode* root) {        
        bool valid = true;
        int min_val{root->val}, max_val{root->val};
        
        if(root->left) {
            auto&&[valid_left, min_left, max_left] = isValid(root->left);
            min_val = min(min_val, min_left);
            max_val = max(max_val, max_left);
            valid = valid && valid_left && root->val > max_left;
        }
        
        if(valid && root->right) {
            auto&&[valid_right, min_right, max_right] = isValid(root->right);
            min_val = min(min_val, min_right);
            max_val = max(max_val, max_right);
            valid = valid && valid_right && root->val < min_right;
        }
        return {valid, min_val, max_val};
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return std::get<0>(isValid(root));
    }
};