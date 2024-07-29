#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wreorder"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wlogical-op-parentheses"
#pragma GCC target("popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC optimize("Ofast")
/************* This code requires C++17. ***************/

// #include<bits/stdc++.h>
// #include <iostream>
#include <iterator>
#include <cstdio>
#include <numeric>
#include <climits>
// #include <vector>
#include <algorithm>
// #include <chrono>
// #include <cstdint>
// #include <limits>
// #include <map>
// #include <queue>
// #include <random>
// #include <set>
// #include <unordered_map>
using namespace std;


#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219
// #define TOT_TEST_CASE 10000

void dump() {}

void dump_ignore() {}

void prep() {
}

int fgcd(int a, int b) {
    int c = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    b >>= __builtin_ctz(b);
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a -= b;
        a >>= __builtin_ctz(a);
        if (a < b) swap(a, b);
    }
    return a << c;
}

constexpr int N = 1e6;
int a[N + 1];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }

    for (int i = N; i; --i) {
        int g = 0;
        for (int j = i; j <= N; j += i) {
            if (a[j] == 0) continue;
            if (g == 0) g = j;
            else if ((g = gcd(g, j)) == i) break;
        }

        if (g == i) {
            a[i] = 1;
        }
    }

    printf("%d\n", count(begin(a), end(a), 1) - n);
    // cout << count(a.begin(), a.end(), 1) - n << '\n';
}

int main() {
#if __cplusplus < 201402L or defined(_MSC_VER) and not defined(__clang__)
    assert(false && "incompatible compiler variant detected.");
#endif
    // untie;
    prep();
#ifdef SINGLE_TEST_CASE
    solve();
#else
    read(int, t);
    for (int i = 0; i < t; ++i) {
#ifdef DUMP_TEST_CASE
        if (t != (TOT_TEST_CASE)) {
            solve();
        } else if (i + 1 == (DUMP_TEST_CASE)) {
            dump();
        } else {
            dump_ignore();
        }
#else
        solve();
#endif
    }
#endif
}
