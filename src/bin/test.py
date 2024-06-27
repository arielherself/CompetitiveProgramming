from math import lcm, ceil, log
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    a = [(0, 0), (2, 16), (30, 14), (4, 6), (2, 10)]
    a.sort(key=lambda t: t[1])
    n = len(a)
    res = []
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(i + 1, j):
                # if (a[j][0] - a[i][0]) * (a[k][1] - a[i][1]) % (a[j][1] - a[i][1]):
                #     continue
                x, y = a[i][0] // 2 + (a[j][0] // 2 - a[i][0] // 2) * (a[k][1] // 2 - a[i][1] // 2 + a[j][1] // 2 - a[i][1] // 2 - 1) // (a[j][1] // 2 - a[i][1] // 2) - a[k][0] // 2, a[i][1] // 2 - a[j][1] // 2
                if (x + y) & 1:
                    res.append((a[i], a[j], a[k], x, y))
    print(res)
