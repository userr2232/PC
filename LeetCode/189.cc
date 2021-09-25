class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count{0};
        for(int start = 0; count < nums.size(); ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while(start != current);
        }
    }
};