class Codec {
    int read_num(int& j, const string& s, int length = -1) {
        int ans{0};
        if(length == -1) while(s[j] != ',') ans *= 10, ans += static_cast<int>(s[j++]-'0');
        else while(--length >= 0) ans *= 10, ans += static_cast<int>(s[j++]-'0');
        return ans;
    }
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto&& str : strs) {
            int length = str.length();
            int length_length = to_string(length).length();
            ans += to_string(length_length) + "," + to_string(length) + str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        const int n = s.length();
        for(int j = 0; j < n;) {
            int length_length = read_num(j, s);
            j++;
            int length = read_num(j, s, length_length);
            ans.emplace_back(s.substr(j, length));
            j += length;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));