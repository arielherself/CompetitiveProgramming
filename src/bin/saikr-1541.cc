/**
 * Author:   subcrip
 * Created:  2024-05-29 14:25:39
 * Modified: 2024-05-29 19:44:59
 * Elapsed:  319 minutes
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

pair<vector<int>, vector<int>> factcount(int n) {
    vector<bool> not_prime(n + 1);
    vector<int> res(n + 1), num(n + 1);
    vector<int> primes;
    res[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (not not_prime[i]) {
            res[i] = 2;
            num[i] = 1;
            primes.emplace_back(i);
        }
        for (auto&& x : primes) {
            if (i * x > n) break;
            not_prime[i * x] = 1;
            if (i % x == 0) {
                num[i * x] = num[i] + 1;
                res[i * x] = res[i] / num[i * x] * (num[i * x] + 1);
                break;
            }
            num[i * x] = 1;
            res[i * x] = res[i] * 2;
        }
    }
    return {primes, res};
}

int main() {
    int n; cin >> n;
    auto [primes, cnt] = factcount(n);
    ll res = 0;
    for (auto&& x : primes) {
        int ab = n - x;
        if (ab <= 0 or ab > n) continue;
        if (ab == 1) {
            res += 1;
        } else if (cnt[ab] > 2) {
            res += cnt[ab];
        }
    }
    cout << res << '\n';
}
