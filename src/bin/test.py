from math import lcm, ceil, log2
from random import choice, randint, shuffle
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    n = 200000
    # m = n // 30
    # print(m * 30)
    # for i in range(m):
    #     for j in range(30):
    #         print(1 << j)
    print(n)
    for i in range(n):
        print(randint(1, 10 ** 9))
    # print(n + 30)
    # for i in range(n):
    #     print(1)
    # for i in range(30):
    #     print(1 << i)
