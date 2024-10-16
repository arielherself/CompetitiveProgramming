from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 100000
    print(1)
    print(N, N, 0, 2 * N)
    print(*[f'{randint(1, N)} {randint(1, N)} {randint(0, (1 << 30) - 1)}' for _ in range(2 * N)], sep = '\n')
