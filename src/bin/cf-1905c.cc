#include<bits/stdc++.h>
using namespace std;
using ull = uint64_t;

constexpr int MAXN = 1e5 + 10;
constexpr ull mdl = 1e9 + 7;

ull table[MAXN + 1];

void prep() {
    ull l1 = 1, l2 = 0;
    for (int i = 0; i < MAXN + 1; ++i) {
        table[i] = (l1 + l2) % mdl;
        l1 = l2;
        l2 = table[i];
    }
}

int main() {
    prep();
    string s; cin >> s;
    s.push_back(0);
    ull res = 1;
    int acc = 0;
    char prev = 0;
    for (auto&& c : s) {
        if (c == 'w' || c == 'm') {
            goto zero;
        }
        if (c != prev) {
            if (prev == 'u' || prev == 'n') {
                res = (res * (table[acc] % mdl)) % mdl;
            }
            acc = 1;
            prev = c;
        } else {
            ++acc;
        }
    }
    cout << res;
    return 0;
    zero: cout << '0';
}