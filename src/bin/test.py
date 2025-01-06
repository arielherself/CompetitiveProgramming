from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 100000
    M = N // 2
    print(N, M, N)
    for i in range(1, M + 1):
        print(randint(1, 2 * i - 1), 2 * i)
    for _ in range(N):
        print(randint(1, N), randint(1, N))
