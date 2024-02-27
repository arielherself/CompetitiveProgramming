#include <bits/stdc++.h>
using namespace std;
template <class __Tp>
struct fenwick : std::vector<__Tp> {
    size_t n;
    fenwick(const size_t &_n) : std::vector<__Tp>(_n + 1), n(_n) {}
    fenwick() {}
    void update(const int &x, const __Tp &val) {
        assert(x > 0);
        for (int i = x; i <= n; i += i & -i) {
            (*this)[i] += val;
        }
    }
    __Tp query(const int &x, __Tp res = 0) {
        assert(x >= 0);
        for (int i = x; i; i -= i & -i) {
            res += (*this)[i];
        }
        return res;
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> F(n + 1), G(n + 1);
    fenwick<int> tr(n);
    vector<int> dep(n + 1), ls(n + 1, -1), l(n + 1), r(n + 1), id(n + 1), sz(n + 1);
    int t = 0;
    function<void(int, int)> dfs = [&](int x, int fa) {
        l[x] = ++t;
        id[t] = x;
        dep[x] = dep[fa] + 1;
        for (auto y : g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            sz[x] += sz[y];
            if (ls[x] == -1 || sz[y] > sz[ls[x]]) ls[x] = y;
        }
        sz[x]++;
        r[x] = t;
    };
    dfs(1, 0);
    function<void(int, int, int)> solveF = [&](int x, int fa, int keep) {
        cerr << "Calling solveF, x = " << x << ", fa = " << fa << ", keep = " << keep << endl;
        for (auto y : g[x]) {
            if (y != fa && y != ls[x]) {
                solveF(y, x, 0);
            }
        }
        if (ls[x] != -1) {
            solveF(ls[x], x, 1);
        }
        for (auto y : g[x]) {
            if (y == fa || y == ls[x]) continue;
            for (int j = l[y]; j <= r[y]; j++) tr.update(id[j], 1);
        }
        tr.update(x, 1);
        F[x] = tr.query(fa);
        cerr << "Writing F[x] = " << F[x] << endl;
        if (!keep) {
            for (int j = l[x]; j <= r[x]; j++) {
                tr.update(id[j], -1);
            }
        }
    };
    function<void(int, int, int)> solveG = [&](int x, int fa, int keep) {
        cerr << "Calling solveG, x = " << x << ", fa = " << fa << ", keep = " << keep << endl;
        for (auto y : g[x]) {
            if (y != fa && y != ls[x]) {
                solveG(y, x, 0);
            }
        }
        if (ls[x] != -1) {
            solveG(ls[x], x, 1);
        }
        for (auto y : g[x]) {
            if (y == fa || y == ls[x]) continue;
            for (int j = l[y]; j <= r[y]; j++) tr.update(id[j], -1);
        }
        tr.update(x, -1);
        G[x] = tr.query(x);
        cerr << "Writing G[x] = " << G[x] << endl;
        if (!keep) {
            for (int j = l[x]; j <= r[x]; j++) {
                tr.update(id[j], 1);
            }
        }
    };

    solveF(1, 0, 1);
    solveG(1, 0, 1);

    fill(tr.begin(), tr.end(), 0);
    vector<long long> f(n + 1);
    function<void(int, int)> get = [&](int x, int fa) {
        tr.update(x, 1);
        for (auto y : g[x]) {
            if (y == fa) {
                continue;
            }
            get(y, x);
        }
        f[1] += dep[x] - tr.query(x);
        tr.update(x, -1);
    };
    function<void(int, int)> ans = [&](int x, int fa) {
        f[x] += f[fa] - F[x] + G[x];
        // 父亲答案 - 当前子树比父亲小的元素个数 + 非当前子树比当前元素小的元素个数
        // 考虑当前元素的ans3，一定也是父亲的ans
        // 考虑当前元素的ans2，要么是父亲的ans3，要么是其他子树中比当前元素小的元素
        // 考虑父亲的ans3，一定可以是当前元素的ans
        // 考虑父亲的ans2，可能是当前子树比父亲小的元素，需要排除。
        for (auto y : g[x]) {
            if (y == fa) {
                continue;
            }
            ans(y, x);
        }
    };

    get(1, 0);
    ans(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << F[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << G[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << f[i] << ' ';
    }
    return 0;
}