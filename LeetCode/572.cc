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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool b = false) {
        if(root == nullptr || subRoot == nullptr) {
            if(root == subRoot) return true;
            else return false;
        }
        if(root->val == subRoot->val) 
            return isSubtree(root->left, subRoot->left, true) && 
                    isSubtree(root->right, subRoot->right, true) || 
            (!b && (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)));
        return !b && 
                (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};