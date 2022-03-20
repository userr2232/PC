class Solution {
public:
    long long maxAlternatingSum(vector<int>& A) {
        const int n = A.size();
        long long odd{0}, even{0}, ans{0};
        for(int i = n-1; i >= 0; --i) {
            const int& num = A[i];
            long long oddmp = max(odd, even+num);
            long long evenmp = max(even, odd-num);
            odd = oddmp, even = evenmp;
            ans = max(odd, even);
        }
        return ans;
    }
};