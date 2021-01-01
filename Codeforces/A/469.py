import sys

lines = iter(sys.stdin.readlines())
n = int(next(lines))
X = set(map(int, next(lines).split()[1:]))
Y = set(map(int, next(lines).split()[1:]))
print("I become the guy." if len(X | Y) == n else "Oh, my keyboard!")