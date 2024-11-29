from sys import stdin
input = stdin.readline
n = int(input())
p = [float(x) for x in input().split(' ')]
ch = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split(' '))
    ch[u].append(v)
    ch[v].append(u)
f = [[0., 0.] for _ in range(n)]
res = 0.
fa = [0] * n
def dfs(v, pa):
    global res
    fa[v] = pa
    f[v] = [1 - p[v], 1]
    for u in ch[v]:
        if u == pa: continue
        dfs(u, v)
        f[v][1] -= 1 - p[u]
    res += f[v][0] * f[v][1]
dfs(0, -1)
q = int(input())
for _ in range(q):
    line = input().split(' ')
    v = int(line[0])
    np = float(line[1])
    res -= f[v][0] * f[v][1]
    f[v][0] = 1 - np
    res += f[v][0] * f[v][1]
    if fa[v] != -1:
        res -= f[fa[v]][0] * f[fa[v]][1]
        f[fa[v]][1] += np - p[v]
        res += f[fa[v]][0] * f[fa[v]][1]
    print(res)
    p[v] = np

