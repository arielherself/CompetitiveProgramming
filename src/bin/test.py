from math import lcm, ceil, log2
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 100000
    print(N)
    print(*(random() for _ in range(N)))
    print(*(f'{randint(0, i - 1)} {i}' for i in range(1, N)), sep='\n')
    print(N)
    for _ in range(N):
        print(randint(0, N - 1), random())
