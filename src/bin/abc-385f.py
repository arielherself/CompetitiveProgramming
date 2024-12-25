from decimal import Decimal
from sys import stdin
input = stdin.readline
n = int(input())
a = [list(map(int, input().split(' '))) for _ in range(n)]
def check(b):
    prev: Decimal = Decimal(-10 ** 18)
    for x, h in a:
        curr: Decimal = (h - b) / x
        if curr > prev:
            prev = curr
        else:
            return False
    return True
if check(0):
    print(-1)
    exit(0)
l = Decimal(0)
r = Decimal(10 ** 18)
cnt = 0
while r - l > 1e-10:
    cnt += 1
    mid = l + (r - l) / 2
    if check(mid):
        r = mid
    else:
        l = mid
print(l)
print(cnt)