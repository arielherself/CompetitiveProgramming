#include <stdio.h>
#define SIZE 3
int main() {
    char array[SIZE] = { 'W', 'T', 'F' };
    for (int i = 0; i < SIZE; ++i) {
        printf("%d=%c ", i, i[array]);
    }
    return 0;
}
