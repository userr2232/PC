class Solution {
    int n, m;
    vector<vector<int>> memo;
    
    int editDistance(int i, int j, const string& word1, const string& word2) {
        if(i == n || j == m) return max(m-j, n-i);
        int& ans = memo[i][j];
        if(ans != -1) return ans;
        if(word1[i] == word2[j]) ans = editDistance(i+1, j+1, word1, word2);
        else {
            ans = 1 + min({editDistance(i+1, j, word1, word2), 
                           editDistance(i, j+1, word1, word2),
                           editDistance(i+1, j+1, word1, word2)});
        }
        return ans;
    }
    
public:
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        memo.assign(n, vector<int>(m, -1));
        return editDistance(0, 0, word1, word2);
    }
};