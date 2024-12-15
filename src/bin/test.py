from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 10 ** 6
    print(N, N)
    print(*(f'{randint(1, N)} {randint(1, N)} {randint(0, 10 ** 8)}' for _ in range(N)))
    print(randint(1, N))
