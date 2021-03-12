class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        
    def pick(self, target: int) -> int:
        n = len(self.nums)
        count = 0
        idx = 0
        for i in range(n):
            if self.nums[i] == target:
                count += 1
                if random.randint(0, count - 1) == 0:
                    idx = i
        return idx