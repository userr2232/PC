class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int max_right{-1}, pos_right{-1};
        pair<int,int> change{0,0};
        for(int i = str.size()-1; i >= 0; --i) {
            int x = str[i]-'0';
            if(x < max_right) {
                change = {i, pos_right};
            }
            else if(x > max_right) {
                max_right = x;
                pos_right = i;
            }
        }
        const auto& [i, j] = change;
        swap(str[i], str[j]);
        int ans{0};
        for(int i = 0; i < str.size(); ++i) ans *= 10, ans += str[i]-'0';
        return ans;
    }
};