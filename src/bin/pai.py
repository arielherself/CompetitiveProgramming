from os import system
from random import randint

for _ in range(10000):
    if _ % 100 == 0:
        print(f'solved: {_}')
    n, x = randint(1, 100), randint(1, 100)
    a = [0] * n
    for i in range(n):
        a[i] = randint(1, 100)
    with open('std.in', 'w') as f:
        print(n, x, file=f)
        print(*a, file=f)
    system('./standard < std.in > standard.out')
    system('./my < std.in > my.out')
    standard_ans, my_ans = '', ''
    with open('standard.out') as f:
        standard_ans = ''.join(f.readlines())
    with open('my.out') as f:
        my_ans = ''.join(f.readlines())
    if standard_ans != my_ans:
        print('input:')
        print(n, x)
        print(*a)
        print('standard answer:')
        print(standard_ans)
        print('my answer:')
        print(my_ans)
        break
