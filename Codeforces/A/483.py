import math

l, r = (map(int, input().split()))
a = l
if a % 2:
    a += 1
if a + 2 > r:
    print(-1)
else:
    print(a, a + 1, a + 2)