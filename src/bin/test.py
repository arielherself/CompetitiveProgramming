from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 1000
    print(N)
    print(*([1000] * 4))
    print(*(''.join((choice(('*', '.')) for _ in range(N))) for _ in range(4)))
