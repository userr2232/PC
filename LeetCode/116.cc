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
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> q;
        q.emplace(root);
        while(!q.empty()) {
            int sz = q.size();
            Node* prev{nullptr};
            for(int i = 0; i < sz; ++i) {
                auto x = q.front(); 
                q.pop();
                if(prev) prev->next = x;
                if(x->left) q.emplace(x->left);
                if(x->right) q.emplace(x->right);
                prev = x;
            }
        }
        return root;
    }
};