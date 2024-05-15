from random import randint
from os import system

while 1:
    n = 5
    ipt = str(n) + '\n'
    for i in range(2, n + 1):
        ipt += f'{randint(1, i - 1)} {i}\n'
    with open('std.in', 'w') as f:
        f.write(ipt)
    system('./bad < std.in > std.out')
    with open('std.out') as f:
        bad = f.read().strip()
    system('./good < std.in > std.out')
    with open('std.out') as f:
        good = f.read().strip()
    if bad != good:
        print('input:', ipt)
        print('bad:', bad)
        print('good:', good)
        break
