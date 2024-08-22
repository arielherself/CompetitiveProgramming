#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

__attribute__((target("lzcnt")))
int main() {
    int x;
    cin >> x;
    cout << __builtin_clzll(x) << '\n';
    // scanf("%d", &x);
    // printf("%d\n", __builtin_popcount(x));
}
