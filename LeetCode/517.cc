class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        const int n = machines.size();
        if(sum % n != 0) return -1;
        int num_dresses_per_machine = sum / n;
        int ans{0};
        sum = 0;
        for(int i = 0; i < n; ++i) {
            ans = max({ans, abs(sum-i*num_dresses_per_machine), machines[i]-num_dresses_per_machine});
            sum += machines[i];
        }
        return ans;
    }
};