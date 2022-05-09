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
class BSTIterator {
    int pos{-1};
    vector<TreeNode*> v;
    stack<TreeNode*> st;
    TreeNode *next_root;
public:
    BSTIterator(TreeNode* root) {
        next_root = root;
    }
    
    bool hasNext() {
        return pos+1 < v.size() || next_root != nullptr || !st.empty();
    }
    
    int next() {
        pos++;
        if(pos == v.size()) {
            auto node = next_root;
            while(node != nullptr) {
                st.emplace(node);
                node = node->left;
            }
            v.emplace_back(st.top());
            st.pop();
            next_root = v.back()->right;
        }
        return v[pos]->val;
    }
    
    bool hasPrev() {
        return pos > 0;
    }
    
    int prev() {
        return v[--pos]->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */