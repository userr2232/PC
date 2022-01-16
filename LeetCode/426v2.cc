/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    void connect(Node* left, Node* right) {
        if(left && right) {
            left->right = right;
            right->left = left;
        }
    }
    
    pair<Node*,Node*> in_order_helper(Node* cur) {
        if(!cur) return {0, 0};
        const auto& [p, mn] = in_order_helper(cur->left);
        connect(p, cur);
        const auto& [mx, s] = in_order_helper(cur->right);
        connect(cur, s);
        return {mx ? mx : cur, mn ? mn : cur};
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return 0;
        const auto& [greatest, smallest] = in_order_helper(root);
        connect(greatest, smallest);
        return smallest;
    }
};