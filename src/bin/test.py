from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 200000
    print(N)
    print(*(randint(0, (2 ** 20) - 1) for _ in range(N)))
    for i in range(2, N + 1):
        print(f'{i} {i - 1}')
    print(N)
    print(*(f'{randint(1, N)} {randint(1, N)} {randint(0, (2 ** 20) - 1)}' for _ in range(N)))
