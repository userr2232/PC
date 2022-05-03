class Solution {
    struct PairHash {
        size_t operator()(pair<int,char> const& p) const {
            return hash<int>()(p.first)^hash<char>()(p.second);
        }
    };
    
    const int MOD = 1e9+7;
    vector<vector<int>> memo;
    unordered_map<pair<int,char>,int,PairHash> count;
    
    int dp(int i, int k, vector<string> const& words, string const& target) {
        if(i == target.length()) return 1;
        if(k == words[0].length()) return 0;
        int& ans = memo[i][k];
        if(ans != -1) return ans;
        ans = dp(i, k+1, words, target);
        auto&& it = count.find(make_pair(k, target[i]));
        if(it == count.end()) return ans;
        ans += 1LL * it->second * dp(i+1, k+1, words, target) % MOD;
        ans %= MOD;
        return ans;
    }
    
public:
    int numWays(vector<string>& words, string target) {
        if(words.empty()) return 0;
        memo.assign(target.length(), vector<int>(words[0].length(), -1));
        for(int i = 0; i < words.size(); ++i) {
            auto&& word = words[i];
            for(int j = 0; j < word.size(); ++j)
                count[make_pair(j, word[j])]++;
        }
        return dp(0, 0, words, target);
    }
};