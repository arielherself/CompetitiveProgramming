from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 500000
    print(N, N // 2)
    for _ in range(2):
        print(*(randint(1, 10 ** 9) for _ in range(N)))
