class Solution {
    deque<string> dq;
    string str;
    void flush() {
        if(str == ".") {}
        else if(str == "..") { if(!dq.empty()) dq.pop_back(); }
        else if(str != "") dq.emplace_back(str);
        str = "";
    }
public:
    string simplifyPath(string path) {
        const int n = path.size();
        for(int i = 0; i < n; ++i) {
            auto c = path[i];
            if(c == '/' or i == n-1) {
                if(c != '/') str += c;
                this->flush();
            }
            else str += c;
        }
        string ans;
        while(!dq.empty()) {
            ans += "/" + dq.front();
            dq.pop_front();
        }
        return ans == "" ? "/" : ans;
    }
};