/**
 * Author:   subcrip
 * Created:  2024-05-29 13:43:45
 * Modified: 2024-05-29 14:11:38
 * Elapsed:  27 minutes
 */

#include <bits/stdc++.h>
using namespace std;

struct quick_union {
    vector<size_t> c, sz;
    int n;
    quick_union(size_t n) : n(n), c(n), sz(n) {
        clear();
    }

    void clear() {
        iota(c.begin(), c.end(), 0);
        sz.assign(n, 1);
    }
    
    size_t query(size_t i) {
        if (c[i] != i) c[i] = query(c[i]);
        return c[i];
    }
    
    void merge(size_t i, size_t j) {
        if (connected(i, j)) return;
        sz[query(j)] += sz[query(i)];
        c[query(i)] = query(j);
    }
    bool connected(size_t i, size_t j) {
        return query(i) == query(j);
    }
    size_t query_size(size_t i) {
        return sz[query(i)];
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    auto dfs = [&] (auto dfs, const vector<vector<int>>& a, int acc) -> void {
        quick_union qu(n * m);
        unordered_set<int> has;
        auto construct = [&] (int id) -> vector<vector<int>> {
            vector<vector<int>> ret = a;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (qu.query(i * m + j) == id) {
                        ret[i][j] = 0;
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                int ptr = n - 1;
                for (int i = n - 1; i >= 0; --i) {
                    while (ptr >= 0 and ret[ptr][j] == 0) {
                        --ptr;
                    }
                    if (ptr < 0) ret[i][j] = 0;
                    else ret[i][j] = ret[ptr--][j];
                }
            }
            return ret;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) continue;
                if (i - 1 >= 0 and a[i][j] == a[i - 1][j]) {
                    qu.merge(i * m + j, (i - 1) * m + j);
                }
                if (i + 1 < n and a[i][j] == a[i + 1][j]) {
                    qu.merge(i * m + j, (i + 1) * m + j);
                }
                if (j - 1 >= 0 and a[i][j] == a[i][j - 1]) {
                    qu.merge(i * m + j, i * m + j - 1);
                }
                if (j + 1 < n and a[i][j] == a[i][j + 1]) {
                    qu.merge(i * m + j, i * m + j + 1);
                }
            }
        }
        int f = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0 or has.count(qu.query(i * m + j))) continue;
                if (qu.query_size(i * m + j) >= 3) {
                    f = 1;
                    dfs(dfs, construct(qu.query(i * m + j)), acc + qu.query_size(i * m + j));
                }
                has.emplace(qu.query(i * m + j));
            }
        }
        if (not f) {
            res = max(res, acc);
        }
    };
    dfs(dfs, a, 0);
    cout << res << '\n';
}

