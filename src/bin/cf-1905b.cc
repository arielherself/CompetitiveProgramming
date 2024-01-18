#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 10;

vector<int> ch[MAXN];

void solve() {
    int n; cin >> n;
    fill(ch, ch + n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        ch[u].push_back(v);
        ch[v].push_back(u);
    }
    int cnt = 0;
    function<void(int, int)> dfs = [&](int v, int pa) {
        int f = 1;
        for (auto&&u : ch[v]) {
            if (u != pa) {
                f = 0;
                dfs(u, v);
            }
        }
        if (f) ++cnt;
    };
    if (n == 2) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (ch[i].size() > 1) {
                dfs(i, 0);
                break;
            }
        }
        cout << (cnt + 1 >> 1) << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}