import sys

t = int(input())
for i in range(t):
    a = int(input())
    print("NO" if 360 % (180 - a) else "YES")