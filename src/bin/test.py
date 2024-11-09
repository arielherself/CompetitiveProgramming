from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 3000
    print(1, N)
    for i in range(2, N + 1):
        print(f'{i} {randint(1, i - 1)}')
