from math import lcm, ceil, log
from random import choice, randint
from os import system
import io

if __name__ == '__main__':
    while True:
        n = randint(1, 5)
        data = io.StringIO()
        print(1, file=data)
        print(n, file=data)
        for i in range(n - 1):
            print(f'{i + 1} {randint(i + 2, n)}', file=data)
        with open('std.in', 'w') as f:
            f.write(data.getvalue())
        system('./a.out < std.in > std.out')
        with open('std.out') as f:
            ans = f.read().strip().split(' ')
            if '0' in ans:
                break
