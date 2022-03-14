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
    pair<vector<int>,vector<bool>> parse(string data) {
        int i{0};
        vector<int> values;
        vector<bool> bitmap;
        bool valid;
        bool negative;
        while(i < data.length()) {
            int num{0};
            valid = true;
            negative = false;
            while(valid && i < data.length() && data[i] != ',') {
                if(data[i] == '#') {
                    valid = false;
                }
                else if(data[i] == '-') {
                    negative = true;
                }
                else {
                    num *= 10;
                    num += data[i]-'0';
                }
                ++i;
            }
            values.emplace_back(num * (negative ? -1 : 1));
            bitmap.emplace_back(valid);
            ++i;
        }
        return {values, bitmap};
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        queue<TreeNode*> q;
        q.emplace(root);
        string ans;
        ans += to_string(root->val);
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            ans += ",";
            if(u->left) {
                ans += to_string(u->left->val);
                q.emplace(u->left);
            }
            else ans += "#";
            ans += ",";
            if(u->right) {
                ans += to_string(u->right->val);
                q.emplace(u->right);
            }
            else ans += "#";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto [v, bitmap] = parse(data);
        int n = v.size();
        TreeNode* root{0};
        if(n && bitmap[0]) root = new TreeNode(v[0]);
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.emplace(root);
        int i{0};
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            if(++i == n) break;
            if(bitmap[i]) {
                q.emplace(u->left = new TreeNode(v[i]));
            }
            if(++i == n) break;
            if(bitmap[i]) {
                q.emplace(u->right = new TreeNode(v[i]));
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));











