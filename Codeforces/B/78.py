n = int(input())
colors = "ROYGBIV"
res = ""
for i in range(n):
    res += colors[i % 7]
if len(res) > 7:
    for idx, c in enumerate(res[-3:], n-3):
        cs = ''.join([ x if x not in res[idx-3:idx] + res[:3-(n-idx)+1] else '' for x in colors])
        if idx < 7:
            s = set(res[:idx])
            cs = [c for c in cs if c not in s]
        res = res[:idx] + cs[0]
print(res)