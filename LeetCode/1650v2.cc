/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
Node* dfs_helper(Node* cur, Node* p, Node* q) {
    if(!cur) return nullptr;
    if(cur == p || cur == q) return cur;
    Node* left = dfs_helper(cur->left, p, q);
    Node* right = dfs_helper(cur->right, p, q);
    if(left && right) return cur;
    if(!left && !right) return nullptr;
    return left ? left : right;
}

public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root{p};
        while(root->parent) root = root->parent;
        return dfs_helper(root, p, q);
    }
};