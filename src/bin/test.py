from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 10 ** 6
    print(N)
    for _ in range(N):
        x, y = randint(1, 10 ** 9), randint(1, 10 ** 9)
        if x > y:
            x, y = y, x
        print(x, y)
