#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n - 1);
    fflush(stdout);
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", n - 1 - i);
        for (int j = i + 1; j <= n - 1; ++j) {
            printf("%d", j);
            if (j == n - 1) printf("\n"), fflush(stdout);
            else printf(" ");
        }

    }
    char* s = new char[n - 1];
    scanf("%s", s);
    for (int i = 0; i < n - 1; ++i) {
        if (i == n - 2) {
            if (s[i] == '1') {
                delete[] s;
                printf("%d\n", i + 1);
                fflush(stdout);
                return 0;
            }
        } else {
            if (s[i] == '1' && s[i+1] == '0') {
                delete[] s;
                printf("%d\n", i + 1);
                fflush(stdout);
                return 0;
            }
        }
    }
    delete[] s;
    printf("%d\n", n);
    fflush(stdout);
    return 0;
}