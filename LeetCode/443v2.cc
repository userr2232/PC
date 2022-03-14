class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int i{0};
        while(i < chars.size()) {
            int group{0};
            char c;
            int j{i};
            for(; j < chars.size(); ++j) {
                if(j == i) {
                    c = chars[j];
                    group++;
                    continue;
                }
                if(chars[j] == c) group++;
                else {
                    break;
                }
            }
            i = j;
            ans.emplace_back(c);
            if(group > 1) {
                string group_str = to_string(group);
                for(auto c : group_str) ans.emplace_back(c);
            }
        }
        chars = ans;
        return chars.size();
    }
};