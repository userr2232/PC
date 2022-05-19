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
    TreeNode* build(int start, int end, vector<int> const& preorder, unordered_map<int,int> const& inorder_m, int&& preorder_idx = 0) {
        if(start > end) return nullptr;
        auto root_val = preorder[preorder_idx++];
        auto root = new TreeNode(root_val);
        auto root_idx = inorder_m.at(root_val);
        root->left = build(start, root_idx-1, preorder, inorder_m, forward<int>(preorder_idx));
        root->right = build(root_idx+1, end, preorder, inorder_m, forward<int>(preorder_idx));
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorder_m;
        const int n = preorder.size();
        for(int i = 0; i < n; ++i) inorder_m[inorder[i]] = i;
        return build(0, n-1, preorder, inorder_m);
    }
};