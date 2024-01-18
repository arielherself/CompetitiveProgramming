#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

void solve() {
    int n, c; cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> idx(n - 1);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (a[i] == a[j]) return i < j;
        return a[i] > a[j];
    });
    ll sum = a[0];
    for (auto&& i : idx) {
        sum += a[i];
        if (sum < (i + 1) * c) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}