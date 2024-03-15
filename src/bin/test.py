n = int(input())
a = []
for i in range(n):
    line = [int(x) for x in input().split(' ')]
    a.append(line)
res = [set() for _ in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(n):
            if j == i or k == i:
                continue
            f = 1
            for l in range(len(a[0])):
                if a[i][l] == a[j][l] and a[j][l] == a[k][l] or a[i][l] != a[j][l] and a[j][l] != a[k][l] and a[k][l] != a[i][l]:
                    continue
                else:
                    f = 0
                    break
            if f: res[i].add(tuple(sorted([i, j, k])))
print(res)

