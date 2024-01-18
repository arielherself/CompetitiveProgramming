#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define msd_power(x) (63LL - __builtin_clz(x))
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll res = 0;
    ll last_power = 0;
    for (int i = 1; i < n; ++i) {
        if (msd_power(a[i]) >= msd_power(a[i-1]) + last_power) {
            ll prev = a[i-1] << last_power;
            if (prev > a[i]) {
                last_power = 1;
            } else {
                last_power = 0;
            }
        } else {
            ll diff = 0;
            if (msd_power(a[i]) <= msd_power(a[i-1])) {
                ll curr = a[i] << (msd_power(a[i-1]) - msd_power(a[i]));
                if (curr < a[i-1]) diff = 1;
            } else {
                ll prev = a[i-1] << (msd_power(a[i]) - msd_power(a[i-1]));
                if (prev > a[i]) diff = 1;
            }
            last_power = msd_power(a[i-1]) + last_power - msd_power(a[i]) + diff;
        }
// cerr << last_power << ' ';
        res += last_power;
    }
// cerr << endl;
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}