class Solution {
public:
    int minimumDeletions(string s) {
        int As{0}, Bs{0};
        for(auto e : s) {
            if(e == 'a') As++; 
        }
        int min_deletions = As;
        for(auto e : s) {
            if(e == 'b') Bs++;
            else As--;
            min_deletions = min(min_deletions, As+Bs);
        }
        return min_deletions;
    }
};