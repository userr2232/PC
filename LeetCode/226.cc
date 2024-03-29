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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        if(root->left && root->right)
            swap(root->left, root->right);
        else if(root->left)
            root->right = root->left, root->left = nullptr;
        else if(root->right)
            root->left = root->right, root->right = nullptr;
        return root;
    }
};