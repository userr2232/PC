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
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right) {
            auto current = node->right;
            while(current->left) current = current->left;
            return current;
        }
        auto parent = node->parent;
        auto current = node;
        while(parent && parent->left != current)
            current = parent, parent = current->parent;
        return parent;
    }
};