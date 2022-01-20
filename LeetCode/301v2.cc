class Solution {
    set<string> ans;
    vector<bool> bitmap;
    int min_paren;
    void backtrack(const string& s, int l, int i, int removed) {
        if(i == s.size()) {
            if(l == 0) {
                string tmp;
                for(int j = 0; j < s.size(); ++j) {
                    if(bitmap[j]) tmp += s[j];
                }
                ans.emplace(move(tmp));
            }
            return;
        }
        char c = s[i];
        if(c != '(' && c != ')') backtrack(s, l, i+1, removed);
        else if(c == ')') {
            if(l == 0) {
                if(removed < min_paren) {
                    bitmap[i] = false;
                    backtrack(s, l, i+1, removed+1);
                    bitmap[i] = true;
                }
            }
            else {
                backtrack(s, l-1, i+1, removed);
                if(removed < min_paren) {
                    bitmap[i] = false;
                    backtrack(s, l, i+1, removed+1);
                    bitmap[i] = true;                    
                }
            }
        }
        else {
            backtrack(s, l+1, i+1, removed);
            if(removed < min_paren) {
                bitmap[i] = false;
                backtrack(s, l, i+1, removed+1);
                bitmap[i] = true;   
            }
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int l{0}, r{0};
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c != '(' && c != ')') continue;
            if(c == '(') l++;
            else {
                if(l == 0) r++;
                else {
                    l--;
                }
            }
        }
        min_paren = l+r;
        bitmap.assign(s.size(), true);
        backtrack(s, 0, 0, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};