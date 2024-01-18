#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
constexpr int MAXN = 42;

int n, m;
ll a[MAXN][MAXN];
ll x[MAXN][MAXN];

int main() {
    cin >> n >> m;
    ll cnt1 = 0, sum1 = 0, cnt2 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if ((i + j) & 1) {
                ++cnt1;
                sum1 += a[i][j];
            } else {
                ++cnt2;
                sum2 += a[i][j];
            }
        }
    }
    ll l = 0, r = LLONG_MAX / (MAXN * MAXN);
    if ((n * m) & 1) {
        l = (sum1 - sum2) / (cnt1 - cnt2);
        r = l + 1;
    }
    ll res = LLONG_MAX;
    int o = 0;
    while(l < r) {
        memset(x, 0, sizeof(x));
        ll mid = l + r >> 1;
        cerr << mid << endl;
        int f = 1;
        ll cnt = 0;
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll available = mid - a[i][j] - x[i][j];
                if (available < 0) {
                    f = 0;
                    goto finish;
                }
                if (i + 1 == n) {
                    if (j + 1 == m) {
                        continue;
                    }
                    ll lo = min(available, mid - a[i][j+1] - x[i][j+1]);
                    x[i][j+1] += lo;
                    if (available != lo) {
                        f = 0;
                        goto finish;
                    }
                } else {
                    if (j + 1 == m) {
                        ll lo = min(available, mid - a[i+1][j] - x[i+1][j]);
                        x[i+1][j] += lo;
                        if (available != lo) {
                            f = 0;
                            goto finish;
                        }
                    } else {
                        ll lo = min(available, mid - a[i][j+1] - x[i][j+1]);
                        x[i][j+1] += lo;
                        x[i+1][j] += available - lo;
                    }
                }
                cnt += 2 * available;
            }
        }
        finish:
        if(f) {
            r = mid;
            o = 1;
            res = min(res, cnt);
        } else {
            l = mid + 1;
        }
    }
    if (o) {
        cout << res;
    } else {
        cout << -1;
    }
}