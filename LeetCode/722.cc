class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string current;
        vector<string> ans;
        bool multiline = false;
        for(const auto& line : source) {
            const int n = line.length();
            for(int i = 0; i < n; ++i) {
                char c = line[i];
                if(multiline) {
                    if(c == '*') {
                        if(i+1 < n && line[i+1] == '/') ++i, multiline = false;
                        else continue;
                    }
                    else continue;
                }
                else {
                    if(c == '/') {
                        if(i+1 < n) {
                            if(line[i+1] == '/') break;
                            else if(line[i+1] == '*') ++i, multiline = true;
                            else current += c;
                        }
                        else {
                            current += c;
                        }
                    }
                    else current += c;
                }
            }
            if(current != "" && !multiline) ans.emplace_back(move(current));
        }
        return ans;
    }
};