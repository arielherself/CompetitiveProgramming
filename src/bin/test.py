from math import lcm, ceil, log
from random import choice, randint
from os import system
import io

if __name__ == '__main__':
    n = 8
    m = 8
    st = set()
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            print(i ** j, end='\t')
            st.add(i ** j)
        print()
    print(len(st))
