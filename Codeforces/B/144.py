from math import hypot

xa, ya, xb, yb = tuple(map(int, input().strip().split()))
n = int(input())

radiators = [tuple(map(int, input().strip().split())) for _ in range(n)]

blankets = 0

def is_in_radius(general, radiator):
    gx, gy = general
    x, y, r = radiator
    if hypot(gx - x, gy - y) <= r: return True
    return False

for x, y in [(xi, ya) for xi in range(min(xa, xb) + 1, (max(xa, xb)))]:
    b = False
    for radiator in radiators:
        if is_in_radius((x, y), radiator):
            b = True
            break
    if not b:
        blankets += 1
        
for x, y in [(xi, yb) for xi in range(min(xa, xb) + 1, (max(xa, xb)))]:
    b = False
    for radiator in radiators:
        if is_in_radius((x, y), radiator):
            b = True
            break
    if not b:
        blankets += 1

for x, y in [(xa, yi) for yi in range(min(ya, yb) + 1, (max(ya, yb)))]:
    b = False
    for radiator in radiators:
        if is_in_radius((x, y), radiator):
            b = True
            break
    if not b:
        blankets += 1

for x, y in [(xb, yi) for yi in range(min(ya, yb) + 1, (max(ya, yb)))]:
    b = False
    for radiator in radiators:
        if is_in_radius((x, y), radiator):
            b = True
            break
    if not b:
        blankets += 1

b = False
for radiator in radiators:
    if is_in_radius((xa, ya), radiator):
        b = True
        break
if not b:
    blankets += 1

b = False
for radiator in radiators:
    if is_in_radius((xa, yb), radiator):
        b = True
        break
if not b:
    blankets += 1

b = False
for radiator in radiators:
    if is_in_radius((xb, ya), radiator):
        b = True
        break
if not b:
    blankets += 1

b = False
for radiator in radiators:
    if is_in_radius((xb, yb), radiator):
        b = True
        break
if not b:
    blankets += 1

print(blankets)