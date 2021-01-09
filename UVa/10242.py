import sys
import operator

for line in sys.stdin.readlines():
    line = line.strip()
    if not line: break
    points = tuple(map(float, line.split()))
    p_d = {}
    common_p = None
    for i in range(0, len(points), 2):
        p = (points[i], points[i+1])
        if not p_d.get(p):
            p_d[p] = 1
        else:
            p_d[p] += 1
            common_p = p
    v0 = common_p
    v1 = None
    v2 = None
    for p in p_d:
        if p_d[p] == 1:
            if not v1:
                v1 = tuple(map(operator.sub, p, common_p))
            else:
                v2 = tuple(map(operator.sub, p, common_p))
    v4 = tuple(map(operator.add, tuple(map(operator.add, v1, v2)), v0))
    print("{:0.3f} {:0.3f}".format(v4[0], v4[1]))