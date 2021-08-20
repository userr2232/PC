class Solution {
    int n;
    void generate(int idleft, int idright, string& current, vector<string>& ans) {
        if(idleft == n && idright == n) { 
            ans.push_back(current);
        }
        int len = current.length();
        if(idleft < n) {
            current += '(';
            generate(idleft+1, idright, current, ans);
            current = current.substr(0, len);
        }
        if(idright < idleft) {
            current += ')';
            generate(idleft, idright+1, current, ans);
            current = current.substr(0, len);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        this->n = n;
        string tmp;
        generate(0, 0, tmp, ans);
        return ans;
    }
};