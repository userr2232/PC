n, k = map(int, input().strip().split())
ys = [*map(int, input().strip().split())]
new_ys = [ y - 1 if 2 <= i + 1 <= 2 * n and not (i + 1) % 2 and ys[i - 1] < y - 1 > ys[i + 1] and k >= 1 and (k := k - 1) + 1 else y for i, y in enumerate(ys) ]
print(' '.join(str(y) for y in new_ys))