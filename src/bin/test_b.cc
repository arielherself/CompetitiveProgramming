#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    vector<int> pa(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        pa[i] = pa[i - 1] + a[i - 1];
        sum += a[i - 1];
    }
    function<int(int)> get = [&](int idx) {
        if (idx + x > n) {
            return pa[n] - pa[idx];
        } else {
            return pa[idx + x] - pa[idx];
        }
    };
    int res = sum - 2 * get(0);
    // cerr << "*" << sum << "*" << get(0) << "*" << res << endl;
    for (int i = 1; i <= k; ++i) {
        sum -= a[i-1];
        res = max(res, sum - 2 * get(i));
        // cerr << "*" << sum << "*" << get(i) << "*" << res << endl;
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}