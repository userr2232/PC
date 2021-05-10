from collections import Counter

t = int(input())
for _ in range(t):
    n = int(input())
    s = {}
    l = input().strip().split()
    counter = Counter(l)
    for k, v in counter.items():
        b = False
        if v == 1:
            for idx, x in enumerate(l):
                if x == k:
                    print(idx + 1)
                    b = True
                    break
        if b: break