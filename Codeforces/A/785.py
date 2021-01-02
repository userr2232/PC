import sys

lines = iter(sys.stdin.readlines())
next(lines)
sum = 0
d = {
    "Tetrahedron": 4,
    "Cube": 6,
    "Octahedron": 8,
    "Dodecahedron": 12,
    "Icosahedron": 20
}
for line in lines:
    sum += d[line.strip()]
print(sum)