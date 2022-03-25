/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* right_neighbor_left_child(Node* current) {
        Node* ans{nullptr};
        while(ans == nullptr && current->next) {
            ans = current->next->left ? current->next->left : current->next->right;
            current = current->next;
        }
        return ans;
    }
    
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node *next_head{root->left ? root->left : root->right}, *current{root};
        while(current || next_head) {
            if(current == nullptr) current = next_head, next_head = nullptr;
            if(current->left) current->left->next = current->right;
            Node* rightmost_child = current->right ? current->right : current->left;
            Node* leftmost_other_child = right_neighbor_left_child(current);
            if(rightmost_child) rightmost_child->next = leftmost_other_child;
            if(next_head == nullptr) {
                next_head = current->left ? current->left : current->right;
            }
            current = current->next;
        }
        return root;
    }
};