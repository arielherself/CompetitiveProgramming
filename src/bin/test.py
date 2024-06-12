from math import lcm, ceil, log
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 1000
    print(1)
    print(3, N * N // 3)
    for i in range(3):
        print(*(choice(['#', '.']) for _ in range(N * N // 3)), sep='')
