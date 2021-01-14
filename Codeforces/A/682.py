n, m = map(int, input().strip().split())
gn, gm = n // 5, m // 5
xn, xm = n % 5, m % 5
count = 0
for i in range(1, xn + 1):
    if 5 - i in [*range(1, xm + 1)]: count += 1
print(gn * gm * 5 + gn * xm + gm * xn + count)