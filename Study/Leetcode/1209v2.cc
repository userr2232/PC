class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
        int j{0};
        for(int i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if(j == 0 || s[j] != s[j-1]) st.push(1);
            else if(++st.top() == k){
                st.pop();
                j -= k;
            }
        }
        return s.substr(0, j);
    }
};