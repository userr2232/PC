class Solution(object):
    def subarraySum(self, nums, k):
        s = 0
        d = {0: 1}
        count = 0
        for j, num in enumerate(nums):
            s += nums[j]
            if d.get(s - k):
                count += d[s - k]
            if d.get(s):
                d[s] += 1
            else:
                d[s] = 1
        return count