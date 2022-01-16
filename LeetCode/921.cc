class Solution {
public:
    int minAddToMakeValid(string s) {
        int l{0}, r{0};
        for(const auto& c : s) {
            if(c == ')') {
                if(l == 0) r++;
                else l--;
            }
            else {
                l++;
            }
        }
        return l + r;
    }
};