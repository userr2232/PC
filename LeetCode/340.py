class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        counter = Counter()
        answer = l = diff = 0
        for r, c in enumerate(s):
            if not counter[s[r]]:
                counter[s[r]] += 1
                diff += 1
                while diff > k:
                    if l >= r: return 0
                    counter[s[l]] -= 1
                    if not counter[s[l]]:
                        diff -= 1
                    l += 1
            else:
                counter[s[r]] += 1
            answer = max(answer, r - l + 1)
        return answer