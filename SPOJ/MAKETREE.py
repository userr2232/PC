# I'm getting TLE with this solution :\

import sys

descendants = {}
ancestors = {}
N = 0
topo_list = []
q = []

def topological_sort():
    u = q.pop(0)
    topo_list.append(u)
    des = descendants.get(u)
    if not des: return
    for v in des:
        ancestors[v].remove(u)
        if not ancestors.get(v):
            q.append(v)

for i, line in enumerate(sys.stdin.readlines()):
    if not i:
        N, _ = (map(int, line.split()))
    else:
        for d in list(map(int, line.split()))[1:]:
            try:
                descendants[i].append(d)
            except:
                descendants[i] = []
                descendants[i].append(d)
            try:
                ancestors[d].add(i)
            except:
                ancestors[d] = set()
                ancestors[d].add(i)

for i in range(1, N + 1):
    if not ancestors.get(i):
        q.append(i)

while q:
    topological_sort()

parent = {}
parent[topo_list[0]] = 0

for idx, v in enumerate(topo_list[1:],1):
    parent[v] = topo_list[idx-1]

for i in range(1, N + 1):
    print(parent[i])