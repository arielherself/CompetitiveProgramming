from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 200000
    print(1, N)
    for i in range(2, N + 1):
        print(randint(1, i - 1), i, randint(1, N), randint(1, N))
