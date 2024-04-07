from random import randint
print(100000)
for _ in range(2):
    for i in range(100000):
        print(randint(0, 1), end='')
    print()
