import sys

_, k = map(int, input().strip().split())
count = 0
lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    if not line: break
    s = sorted(list(set(map(int, line))))
    if len(s) >= k + 1 and s[k] == k:
        count += 1
print(count)