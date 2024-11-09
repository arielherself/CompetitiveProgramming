#include <bits/stdc++.h>
constexpr int P = 998244353;
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> f(k + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0, p = 1; j <= k; ++j) {
            f[j] = (f[j] + p) % P;
            p = int64_t(p) * a[i] % P;
        }
    }
    std::vector<std::vector<int>> c(k + 1, std::vector<int>(k + 1));
    for (int i = 0; i <= k; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
    }
    std::vector<int> g(k + 1);
    for (int i = 0; i <= k; ++i)
        for (int j = 0; i + j <= k; ++j) g[i + j] = (g[i + j] + int64_t(f[i]) * f[j] % P * c[i + j][i]) % P;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, p = 1; j <= k; ++j) {
            g[j] = (g[j] - p + P) % P;
            p = int64_t(p) * a[i] * 2 % P;
        }
    }
    int64_t res = 0;
    int choice = 1;
    for (int i = 1; i <= k; ++i) {
        int64_t curr = int64_t(g[i]) * (P + 1) / 2 % P;
        if (curr >= res) {
            res = curr;
            choice = i;
        }
    }
    std::cout << choice << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) solve();
}
