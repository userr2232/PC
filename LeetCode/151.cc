class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> v;
        string str;
        while(iss >> str) v.emplace_back(move(str));
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); ++i) {
            if(i) str += " ";
            str += move(v[i]);
        }
        return str;
    }
};