#include<bits/stdc++.h>
using namespace std;



void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        seg[i] = {l, r};
    }
    sort(seg.begin(), seg.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    });
    int res = 0;
    set<pair<int, int>> lefts;
    set<pair<int, int>> rights;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        auto&& [l, r] = seg[i];
        if (l == 1 || l == prev) continue;
        prev = l;
        auto rp = rights.begin();
        while (rights.size() && rp->first < l) {
            lefts.erase({seg[rp->second].first, rp->second});
            rp = rights.erase(rp);
        }
        lefts.insert({l, i});
        rights.insert({r, i});
        res = max(res, int(lefts.size()));
        cerr << lefts.size() << ' ' << res << endl;
    }
    lefts.clear(), rights.clear(), prev = 0;
    
    cout << res << endl;
}











int main() {
    int t; cin >> t;
    while (t--) solve();
}
