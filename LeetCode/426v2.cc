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
    pair<Node*,Node*> in_order_helper(Node* cur) {
        if(!cur) return {0, 0};
        if(cur->left) {
            const auto& [p, _] = in_order_helper(cur->left);
            p->right = cur;
            cur->left = p;
        }
        if(cur->right) {
            const auto& [_, s] = in_order_helper(cur->right);
            s->left = cur;
            cur->right = s;                
        }
        Node *p{cur}, *s{cur};
        while(p->right) p = p->right;
        while(s->left) s = s->left;
        return {p, s};
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return 0;
        const auto& [greatest, smallest] = in_order_helper(root);
        smallest->left = greatest;
        greatest->right = smallest;
        return smallest;
    }