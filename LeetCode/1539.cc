class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing{0}, missing_counter{0};
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            missing_counter += arr[i] - ++missing;
            missing = arr[i];
            if(missing_counter >= k) return missing - (missing_counter - k) - 1;
        }
        return missing + k - missing_counter;
    }
};