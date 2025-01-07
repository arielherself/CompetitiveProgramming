from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    res = 0
    N = 75
    for i in range(N):
        for j in range(i + 1, N):
            for k in range(0, j - i + 1 + 1):
                for l in range(0, j - i + 1 - k + 1):
                    for m in range(0, (j - i + 1) // 2 + 1):
                        res += 1
    print(res)
