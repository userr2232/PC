class Solution {
    // () -> 1
    // ()) -> 0
    // ) -> 2
    // )) -> 1
public:
    int minInsertions(string s) {
        const int n = s.length();
        int ans{0}, open{0};
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') open++;
            else {
                if(i == n-1 || s[i+1] != ')') {
                    if(open) open--, ans++;
                    else ans += 2;
                }
                else {
                    if(open) open--;
                    else ans++;
                    i++;
                }
            }
        }
        return ans + (open << 1);
    }
};