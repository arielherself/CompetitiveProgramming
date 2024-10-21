from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 50
    print(N, N)
    print(*[randint(1, N) for _ in range(N)])
    print(*[randint(1, N) for _ in range(N)])
