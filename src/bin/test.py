from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 50
    print(N)
    for i in range(2, N + 1):
        print(f'{randint(1, i - 1)} {i} {randint(100000000, 999999999)}')
    print(f'1 50 {randint(100000000, 999999999)}')
