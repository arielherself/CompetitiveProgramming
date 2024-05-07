from random import shuffle, randint
from os import system

def gen_tree(n):
    tree = ''
    for i in range(2, n + 1):
        fa = randint(1, i - 1)
        tree += f'{fa} {i}\n'
    return tree

if __name__ == '__main__':
    while 1:
        n = randint(2, 10)
        tr = gen_tree(n)
        val = ' '.join([str(randint(-10, 10)) for _ in range(n)])
        content = '\n'.join((str(n), val, tr))
        with open('std.in', 'w') as f:
            f.write('1\n' + content)
        system('./my.out < std.in > std.out')
        with open('std.out') as f:
            my_ans = f.read().strip()
        system('./ans.out < std.in > std.out')
        with open('std.out') as f:
            his_ans = f.read().strip()
        if my_ans != his_ans:
            print(content)
            print(my_ans)
            print(his_ans)
            break
