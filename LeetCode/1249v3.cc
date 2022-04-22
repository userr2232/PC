class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open{0};
        string ans;
        for(auto&& c : s) {
            switch(c) {
                case '(':
                    open++;
                    ans += c;
                    break;
                case ')':
                    if(open > 0) open--, ans += c;
                    break;
                default:
                    ans += c;
                    break;
            }
        }
        string reversed_ans;
        reverse(ans.begin(), ans.end());
        for(auto&& c : ans)
            if(c == '(') {
                if(open-- > 0) continue;
                else reversed_ans += c;
            }
            else reversed_ans += c;
        reverse(reversed_ans.begin(), reversed_ans.end());
        return reversed_ans;
    }
};