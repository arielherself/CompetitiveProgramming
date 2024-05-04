from random import shuffle, randint
from itertools import pairwise
from os import system

while True:
    n = randint(2, 10)
    a = list(range(n))
    shuffle(a)
    inp = [str(i ^ j) for i, j in pairwise(a)]
    with open('std.in', 'w') as f:
        f.write(str(n) + '\n' + ' '.join(inp))
    ret = system('./a.out < std.in > /dev/null')
    if ret:
        print(a)
        print(inp)
        break

