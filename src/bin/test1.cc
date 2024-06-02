/**
 * Author:   subcrip
 * Created:  2024-06-02 11:52:54
 * Modified: 2024-06-02 11:55:42
 * Elapsed:  2 minutes
 */

#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 50010;
int low[MAXN], dfn[MAXN], dfs_clock;
bool isbridge[MAXN];
vector<int> ch[MAXN];
int cnt_bridge;
int father[MAXN];

void tarjan(int u, int fa) {
  father[u] = fa;
  low[u] = dfn[u] = ++dfs_clock;
  for (int i = 0; i < ch[u].size(); i++) {
    int v = ch[u][i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        isbridge[v] = true;
        ++cnt_bridge;
      }
    } else if (dfn[v] < dfn[u] && v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        ch[u].emplace_back(v);
        ch[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (not dfn[i]) tarjan(i, 0);
    }
    cout << count(begin(isbridge), end(isbridge), 1) << '\n';
}
