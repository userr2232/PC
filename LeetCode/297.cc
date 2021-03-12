class Codec {
public:
    string serialized;
    Codec() {serialized = "";}
    
    void BFS(TreeNode* current) {
        if(!current) {
            serialized = "null";
            return;
        }
        queue<pair<TreeNode*,int>> q;
        set<int> levels;
        map<int, string> level_string;
        q.push({current,0});
        cout << current->left << " " << current->right << endl;
        while(!q.empty()) {
            auto [current_node, current_level] = q.front();
            q.pop();
            if(current_node) {
                levels.insert(current_level);
                if(!level_string.count(current_level))
                    level_string[current_level] = "";
                level_string[current_level] += to_string(current_node->val) + ",";
                q.push({current_node->left, current_level+1});
                q.push({current_node->right, current_level+1});
            }
            else {
                if(!level_string.count(current_level))
                    level_string[current_level] = "";
                level_string[current_level] += "null,";
                continue;
            }
        }
        for(auto [level, ser_string] : level_string) {
            if(levels.count(level)) {
                serialized += ser_string;
            }
        }
        serialized = serialized.substr(0, serialized.length()-1);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        BFS(root);
        return serialized;
    }
    
    queue<string> split(string s, char delimiter = ',') {
        cout << "string: " << s << endl;
        string token;
        istringstream iss(s);
        queue<string> results;
        while(getline(iss, token, delimiter)) {
            // cout << "token: " << token << endl;
            results.push(token);
        }
        return results;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto ser = split(data);
        queue<TreeNode*> prevs;
        bool left = true;
        TreeNode* root{0};
        while(!ser.empty()) {
            // cout << "entra" << endl;
            auto current = ser.front();
            // cout << "current: " << current << endl;
            ser.pop();
            if(current != "null") {
                TreeNode* new_node = new TreeNode{stoi(current),nullptr,nullptr};
                if(!root) root = new_node;
                if(!prevs.empty()) {
                    if(left) {
                        auto prev = prevs.front();
                        prev->left = new_node;
                        left = false;
                    }
                    else {
                        auto prev = prevs.front();
                        prevs.pop();
                        prev->right = new_node;
                        left = true;
                    }
                }
                prevs.push(new_node);
            }
            else {
                if(left) left = false;
                else {
                    left = true;
                    if(!prevs.empty())
                        prevs.pop();
                }
            }
            // cout << "sale" << endl;
        }
        // cout << root->left->val << " " << root->right->val << endl;
        return root;
    }
};