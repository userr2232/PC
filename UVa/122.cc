#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef vector<int> vi;

bool incomplete_tree = true, printed = false, invalid = false;

struct Tree{
    int val = -1;
    Tree *left{0}, *right{0};
};

int read_int(int& i, string& str) {
    int ans{0};
    for(; i < str.size(); ++i) if(isdigit(str[i])) ans *= 10, ans += str[i]-'0'; else break;
    return ans;
}

string read_path(int& i, string& str) {
    string ans;
    for(; i < str.size(); ++i) if(str[i] == 'L' || str[i] == 'R') ans += str[i]; else break;
    return ans;
}

pair<int,string> parse_token(int& i, string& str) {
    // cerr << "parsing token: " << str.substr(i) << endl;
    for(; i < str.size(); ++i) if(str[i] == '(') break;
    if(str[i] == '(' && str[i+1] == ')') {
        i = str.size();
        incomplete_tree = false;
        return {-1, ""};
    }
    ++i;
    int val = read_int(i, str);
    ++i;
    string path = read_path(i, str);
    ++i;
    return {val, path};
}

void insert_line(Tree*& root, string& str) {
    if(root == nullptr) root = new Tree();
    for(int i = 0; i < str.size(); ++i) {
        auto [val, path] = parse_token(i, str);
        Tree* current = root;
        // cerr << "parsed: " << val << " " << path << endl;
        for(auto c : path) {
            if(c == 'L') {
                if(current->left == nullptr) current->left = new Tree();
                current = current->left;
            }
            else if(c == 'R') {
                if(current->right == nullptr) current->right = new Tree();
                current = current->right;
            }
            else {
                // cerr << "found path " << path << endl;
                // cerr << "undefined behaviour" << endl;
            }
        }
        if(val != -1) {
            if(current->val != -1) invalid = true;
            current->val = val;
        }
        // cerr << "root: " << root->val << endl;
    }
}

string print_tree(Tree* root) {
    queue<Tree*> q;
    if(root == nullptr) return "";
    else q.emplace(root);
    bool printed_one = false;
    string ans;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            Tree* current = q.front();
            q.pop();
            if(current->val == -1) return "";
            ans += (printed_one ? " " : "") + to_string(current->val);
            printed_one = true;
            if(current->left) q.emplace(current->left);
            if(current->right) q.emplace(current->right);
        }
    }
    printed = true;
    return ans;
}

int main() {
    string line;
    // cerr << "stuck 0" << endl;
    while(getline(cin, line)) {
        // cerr << "stuck 1" << endl;
        Tree *root{0};
        invalid = false;
        insert_line(root, line);
        while(incomplete_tree) {
            // cerr << "stuck 2" << endl;
            getline(cin, line);
            insert_line(root, line);
        }
        // cerr << "reaches this point" << endl;
        incomplete_tree = true;
        string ans = print_tree(root);
        if(!invalid && printed) {
            printed = false;
            cout << ans << endl;
        }
        else {
            cout << "not complete" << endl;
        }
    }
}