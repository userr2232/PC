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
    unordered_map<int,int> inorder_index;
    int root_index{0};
    
    TreeNode* buildTree(const vector<int>& preorder, int&& l, int&& r) {
        if(l > r) return nullptr;
        auto&& root_val = preorder[root_index++];
        auto&& root_index = inorder_index[root_val];
        TreeNode* root = new TreeNode(root_val);
        root->left = buildTree(preorder, forward<int>(l), forward<int>(root_index-1));
        root->right = buildTree(preorder, forward<int>(root_index+1), forward<int>(r));
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int n = inorder.size();
        if(n == 0) return nullptr;
        for(int i = 0; i < n; ++i)
            inorder_index[inorder[i]] = i;
        return buildTree(preorder, 0, n-1);
    }
};