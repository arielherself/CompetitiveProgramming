from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 2 * (10 ** 5)
    print(N)
    for i in range(N):
        print(i + 1, randint(1, 10 ** 9))