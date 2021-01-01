import sys

descendants = {}
ancestors = {}
N = 0
topo_list = []
q = []

def reset():
    global setup, descendants, ancestors, N, topo_list, q
    setup = True
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

setup = True

lines = iter(sys.stdin.readlines())

for line in lines:
    if setup:
        N, K = (map(int, line.split()))
        setup = False
        if N == 0 and K == 0:
            break
    for i in range(K):
        a, d = (map(int, next(lines).split()))
        try:
            descendants[a].append(d)
        except:
            descendants[a] = []
            descendants[a].append(d)
        try:
            ancestors[d].add(a)
        except:
            ancestors[d] = set()
            ancestors[d].add(a)
    
    for i in range(1, N + 1):
        if not ancestors.get(i):
            q.append(i)

    while q:
        topological_sort()

    print(' '.join(str(x) for x in topo_list))
    reset()