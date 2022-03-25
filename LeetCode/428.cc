/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
    string dfs_helper(Node* current) {
        if(!current) return "";
        string ans = to_string(current->val);
        if(!current->children.empty()) ans += "[";
        for(auto child : current->children) ans += dfs_helper(child) + " ";
        if(!current->children.empty()) ans += " ]";
        return ans;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        return "[" + dfs_helper(root) + " ]";
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stack<Node*> st;
        int current{0};
        bool valid{false};
        Node* head{nullptr};
        for(int i = 0; i < data.length(); ++i) {
            char c = data[i];
            switch(c) {
                case ' ':
                    if(valid) {
                        valid = false;
                        auto node = new Node(current);
                        if(!head) head = node;
                        if(!st.empty()) st.top()->children.emplace_back(node);
                    }
                    break;
                case '[':
                    if(valid) {
                        valid = false;
                        auto node = new Node(current);
                        if(!head) head = node;
                        if(!st.empty()) st.top()->children.emplace_back(node);
                        st.emplace(node);
                    }
                    break;
                case ']':
                    if(!st.empty()) st.pop();
                    break;
                default:
                    if(!valid) current = 0, valid = true;
                    current *= 10;
                    current += static_cast<int>(c-'0');
                    break;
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));