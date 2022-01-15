class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> um;
        for(int i = 0; i < order.length(); ++i)
            um[order[i]] = i;
        for(auto& word : words)
            for(auto& c : word)
                c = um[c];
        for(int i = 1; i < words.size(); ++i) {
            if(words[i] >= words[i-1]) continue;
            return false;
        }
        return true;
    }
};