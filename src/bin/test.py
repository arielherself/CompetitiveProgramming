from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 300000
    print(N)
    print(*[randint(1, 10 ** 9) for _ in range(N)])
    print(N)
    for _ in range(N):
        print(f'2 {N - 1} {10 ** 9}')
