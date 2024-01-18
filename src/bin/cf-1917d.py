from sortedcontainers import SortedList

def solve():
    n, k = [int(x) for x in input().strip().split(' ')]
    p = [int(x) for x in input().strip().split(' ')]
    q = [int(x) for x in input().strip().split(' ')]
    assert n == len(p) and k == len(q)
    st = SortedList()
    res = 0
    for i in range(n - 1, -1, -1):
        res += st.bisect_left(p[i])
        res += 