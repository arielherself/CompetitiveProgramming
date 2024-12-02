from math import lcm, ceil, log2
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 200000
    print(N)
    print(*(166320 for _ in range(N)))
    print(*(f'{i} {randint(1, i - 1)}' for i in range(2, N + 1)))
