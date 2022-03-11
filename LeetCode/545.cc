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
    void dfs(TreeNode* current, vector<int>& leaves) {
        if(current == nullptr) return;
        if(current->left == nullptr && current->right == nullptr) leaves.emplace_back(current->val);
        else {
            dfs(current->left, leaves);
            dfs(current->right, leaves);
        }
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        ans.emplace_back(root->val);
        vector<int> leaves, left_boundary, right_boundary;
        TreeNode* current = root->left;
        while(current && (current->left != nullptr || current->right != nullptr)) {
            left_boundary.emplace_back(current->val);
            if(current->left) current = current->left;
            else if(current->right) current = current->right;
        }
        current = root->right;
        while(current && (current->left != nullptr || current->right != nullptr)) {
            right_boundary.emplace_back(current->val);
            if(current->right) current = current->right;
            else if(current->left) current = current->left;
        }
        dfs(root->left, leaves);
        dfs(root->right, leaves);
        for(auto e : left_boundary) ans.emplace_back(e);
        for(auto e : leaves) ans.emplace_back(e);
        reverse(right_boundary.begin(), right_boundary.end());
        for(auto e : right_boundary) ans.emplace_back(e);
        return ans;
    }
};