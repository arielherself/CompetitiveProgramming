from math import lcm, ceil, log2
from string import ascii_lowercase
from random import choice, randint, shuffle, random
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    N = 10 ** 5
    print(''.join((choice(ascii_lowercase) for _ in range(N))))
    # print(''.join(('a' for _ in range(N))))
    print(N)
    rem = N
    for i in range(N):
        # m = randint(1, rem - (N - 1 - i))
        # m = 316
        m = 1
        rem -= m
        if rem < 0:
            break
        print(f'{randint(1, N)} {"".join((choice(ascii_lowercase) for _ in range(m)))}')
        # print(f'{randint(1, N)} {"".join(("a" for _ in range(m)))}')
