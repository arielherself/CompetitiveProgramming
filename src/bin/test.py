from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 400000
    M = 200000
    print(N, M)
    print('64 ' * N)
    print(f'TOTIENT 1 {N} ' * M)
