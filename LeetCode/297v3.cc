/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void serialize(TreeNode* current, string& str) {
        if(current == nullptr) {
            str += "X ";
            return;
        }
        str += to_string(current->val) + " ";
        serialize(current->left, str);
        serialize(current->right, str);
    }
    
    TreeNode* deserialize(istringstream&& iss) {
        string str;
        iss >> str;
        if(str == "X") return nullptr;
        auto node = new TreeNode(stoi(move(str)));
        node->left = deserialize(forward<istringstream>(iss));
        node->right = deserialize(forward<istringstream>(iss));
        return node;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        serialize(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        return deserialize(istringstream(data));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));