#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll solve(vector<vector<ll>> boxes) {
    int m = boxes.size();
    int n = m * 3;
    for (int i = 0; i < m; ++i) {
        boxes.push_back({boxes[i][0], boxes[i][2], boxes[i][1]});
        boxes.push_back({boxes[i][1], boxes[i][2], boxes[i][0]});
    }
    vector<vector<int>> ch(n);
    vector<int> ind(n, 0);
    function<bool(const vector<ll>&, const vector<ll>&)> is_fit = [](const vector<ll>& x, const vector<ll>& y) {
        return x[0] < y[0] && x[1] < y[1] || x[0] < y[1] && x[1] < y[0];
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n ;++j) {
            if (is_fit(boxes[j], boxes[i])) {
                ch[i].push_back(j);
                ++ind[j];
            }
        }
    }
    ll res = 0;
    deque<int> dq;
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!ind[i]) dq.push_back(i);
    }
    while (!dq.empty()) {
        int i = dq.front();
        dq.pop_front();
        dp[i] += boxes[i][2];
        res = max(res, dp[i]);
        for (auto&& j : ch[i]) {
            dp[j] = max(dp[j], dp[i]);
            --ind[j];
            if (!ind[j]) dq.push_back(j);
        }
    }
    return res;
}

int main() {
    int i = 0;
    while (1) {
        ++i;
        int n;
        cin >> n;
        if (!n) break;
        vector<vector<ll>> boxes(n);
        for (int i = 0;i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int t; cin >> t; boxes[i].push_back(t);
            }
        }
        cout << "Case " << i << ": maximum height = " << solve(move(boxes)) << endl;
    }
}