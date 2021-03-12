class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        stickers.sort(key=lambda k: len(k), reverse=True)
        stickers = [Counter(sticker) for sticker in stickers]
        memo = {'': 0}
        def DFS(target):
            if target in memo:
                return memo[target]
            res = float("inf")
            for sticker in stickers:
                newtarget = target
                if target[0] not in sticker:
                    continue
                for c, num in sticker.items():
                    newtarget = newtarget.replace(c, '', num)
                if newtarget == '':
                    res = 1
                    break
                elif newtarget != target:
                    res = min(res, 1 + DFS(newtarget))
            memo[target] = res
            return res
        res = DFS(target)
        if res == float("inf"):
            return -1
        else:
            return res