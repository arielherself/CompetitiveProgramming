from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 200000
    M = 60
    P = 15
    print(N, M, P)
    for i in range(N):
        print('1' * P + '0' * (M - P))
