class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l{0}, r{0};
        vector<int> to_remove;
        int N = s.length();
        for(int i = 0; i < N; ++i) {
            char c = s[i];
            if(c == ')') {
                if(l > 0) {
                    --l;
                    to_remove.pop_back();
                }
                else {
                    ++r;
                    to_remove.emplace_back(i);
                }
            }
            else if(c == '(') {
                ++l;
                to_remove.emplace_back(i);
            }
            else continue;
        }
        string ans;
        int j{0};
        for(int i = 0; i < N; ++i) {
            if(j < to_remove.size() && to_remove[j] == i) {
                ++j;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};