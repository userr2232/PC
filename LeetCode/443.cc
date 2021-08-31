class Solution {
public:
    int compress(vector<char>& chars) {
		if(chars.size() <= 1) return chars.size();
        int i{0}, j{0};
        while(i < chars.size()) {
            chars[j] = chars[i];
            int len{0};
            while(i < chars.size() && chars[j] == chars[i]) ++i, len++;
            if(len == 1) ++j;
            else {
                string str_len = to_string(len);
                for(int k = 0; k < str_len.size(); ++k) chars[++j] = str_len[k];
                j++;
            }
        }
        chars.erase(chars.begin()+j, chars.end());
        return chars.size();
    }
};