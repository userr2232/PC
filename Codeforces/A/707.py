import sys

_, _ = (input().split())
lines = iter(sys.stdin.readlines())
out = False
for line in lines:
    row = set(line.split())
    if 'C' in row or 'M' in row or 'Y' in row:
        out = True
        print("#Color")
        break
if not out:
    print("#Black&White")