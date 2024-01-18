n = int(input())
for i in range(n + 1):
    for j in range(n - i + 1):
        for k in range(n - i - j + 1):
            print(i, j, k)