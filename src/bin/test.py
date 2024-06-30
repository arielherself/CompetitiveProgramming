from math import lcm, ceil, log
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    n = 4
    k = 5
    for i in range(1 << n * k):
        j = i
        cnt = (j & ((1 << n) - 1)).bit_count()
        f = 1
        for _ in range(k):
            if (j & ((1 << n) - 1)).bit_count() != cnt:
                f = 0
                break
            j >>= n
        for j in range(n):
            l = i >> j
            c = 0
            while l:
                c += l & 1
                l >>= n
            if (c & 1) == 0:
                f = 0
                break
        if f:
            m = i
            for j in range(k):
                for l in range(n):
                    print(m & 1, end='')
                    m >>= 1
                print()
            print()

