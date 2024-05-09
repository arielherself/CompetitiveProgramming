from itertools import pairwise
from random import shuffle, randint
from os import system

def gen_tree(n):
    tree = ''
    for i in range(2, n + 1):
        fa = randint(1, i - 1)
        tree += f'{fa} {i}\n'
    return tree

N = 10_000_000
prime = []
is_prime = [False] * N

def Eratosthenes(n):
    is_prime[0] = is_prime[1] = False
    for i in range(2, n + 1):
        is_prime[i] = True
    for i in range(2, n + 1):
        if is_prime[i]:
            prime.append(i)
            if i * i > n:
                continue
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

if __name__ == '__main__':
    print(1)
    print(1000000)
    print('8 6 ' * 500000)
