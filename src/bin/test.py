from math import lcm, ceil, log2
from random import choice, randint
from os import system
from collections import defaultdict
import io

PRIME = 998_244_353

if __name__ == '__main__':
    while True:
        N = randint(1, 200)
        with open('std.in', 'w') as f:
            print(N, file=f)
            for _ in range(N):
                print(randint(1, 200), file=f)
        system('./good < std.in > std.out')
        with open('std.out') as f:
            good = f.read().strip()
        system('./bad < std.in > std.out')
        with open('std.out') as f:
            bad = f.read().strip()
        if good != bad:
            print('good:')
            print(good)
            print()
            print('bad:')
            print(bad)
            break
