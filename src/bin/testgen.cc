#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    int sq = sqrt(x);
    for (int i = 2; i <= sq; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        using ll = int64_t;
        using pii = pair<ll, ll>;
        ll res = 0;
        vector<pii> dp(n + 1);
        unordered_set<int> prime_table;
        for (int i = 2; i <= n; ++i) {
            if (isprime(i)) prime_table.insert(i);
        }
        auto dfs = [&] (auto dfs, int v, int pa) -> void {
            ll cs = 0, cn = 0;
            cerr << "v=" << v << endl;;
            for (auto&& u : edges[v-1]) {
                if (u == pa) continue;
                dfs(dfs, u, v);
                cs += dp[u].first;
                cn += dp[u].second;
            }
            if (prime_table.count(v)) {
                ll curr = 0;
                for (auto&& u : edges[v-1]) {
                    if (u == pa) continue;
                    curr += dp[u].second * (cn - dp[u].second + 1);
                }
                curr /= 2;
                res += curr;
                dp[v] = {cn, 0};
            } else {
                ll curr = 0;
                for (auto&& u : edges[v-1]) {
                    if (u == pa) continue;
                    curr += dp[u].first * (cn - dp[u].second + 1);
                }
                curr /= 2;
                res += curr;
                dp[v] = {cs, cn};
            }
        };
        dfs(dfs, 1, 0);
        return res;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    cout << Solution().countPaths(n, edges) << endl;
} 
