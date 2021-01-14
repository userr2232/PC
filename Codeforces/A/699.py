n = int(input())
d = input().strip()
p = [*map(int, input().strip().split())]
if 'RL' not in d:
    print(-1)
else:
    di = iter(d)
    t = 2e9
    i = 0
    for _ in di:
        if d[i : i + 2] == 'RL':
            t = min(t, (p[i + 1] - p[i]) // 2)
            next(di)
            i += 1
        i += 1
    print(t)