def diff(a, b):
    n = len(a)
    res = 0
    for i in range(n):
        if a[i] != b[i]:
            for j in range(i + 1, n):
                if b[j] == a[i]:
                    res += j - i
                    b = b[:i] + b[j] + b[i:j] + b[j+1:]
                    break
    return res
