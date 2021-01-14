import sys

_ = input()
x = int(input())
_, _ = map(int, input().strip().split())
p = True
prev = 7 - x
lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    if not line: break
    a, b = map(int, line.split())
    if prev in [a, 7-a, b, 7-b]:
        p = False
        break
print("YES" if p else "NO")