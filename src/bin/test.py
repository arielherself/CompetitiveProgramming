from typing import DefaultDict


n = int(input())
a = [int(x) for x in input().strip().split(' ')]
d = sorted(list(set(a)), reverse=True)
a.sort()
slot = DefaultDict(lambda: [])
slot_cnt = DefaultDict(lambda: 0)
for i in range(n):
    for j in range(i + 1, n):
        for k in d:
            if a[i] % k == 0 and a[j] % k == 0:
                slot[k].append((a[i], a[j]))
                slot_cnt[k] += 1
                break

print(slot)
print(n * (n - 1) // 2 - sum(v for v in slot_cnt.values()))
