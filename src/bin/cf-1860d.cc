$include(template.hh);

#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219

void dump() {}

void dump_ignore() {}

void prep() {}

void solve() {
    $read(string, s);
    int n = s.size();
    vector<int> a;
    for (auto&& x : s) a.emplace_back(x - 48);
    int m = 2 * n * n + 10;
    vector<array<vector<int>, 2>> dp(n + 1, {vector<int>(m, INF), vector<int>(m, INF)});
    array<int, 2> prev {-INF, -INF};
    dp[1][a[0]][n * n] = 0;
    prev[a[0]] = 0;
    int cnt1 = a[0];
    for (int i = 1; i < n; ++i) {
        int add = a[i] ? cnt1 - i : cnt1;
        for (int j = 0; j < 2 * n * n + 10; ++j) {
            // swap
            dp[i + 1][1 ^ a[i]][j + i - prev[1 ^ a[i]] + add] = dp[i];
        }
        cnt1 += a[i];
    }
    $debug(dp[2][1][n * n], dp[3][0][n * n + 2]);
    cout << min(dp[n][0][n * n], dp[n][1][n * n]) << '\\n';
}

$include(mian.hh)
