n = int(input())
l = [*map(int, input().strip().split())]

l = [0] + l
e = 0
res = 0
for idx, c in enumerate(l[1:], 1):
    e += l[idx - 1] - c
    if e < 0:
        res += -e
        e = 0
print(res)