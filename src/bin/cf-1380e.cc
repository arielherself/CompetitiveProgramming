// #pragma GCC target("popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC optimize("Ofast")
/************* This code requires C++17. ***************/

#include<bits/stdc++.h>
using namespace std;

/* macro helpers */
constexpr void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()

/* type aliases */
#if LONG_LONG_MAX != INT64_MAX
using ll = int64_t;
using ull = uint64_t;
#else
using ll = long long;
using ull = unsigned long long;
#endif
using int128 = __int128_t;
using uint128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;           using pil = pair<int, ll>;           using pid = pair<int, ld>;
using pli = pair<ll, int>;            using pll = pair<ll, ll>;            using pld = pair<ll, ld>;
using pdi = pair<ld, int>;            using pdl = pair<ld, ll>;            using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;    using tiil = tuple<int, int, ll>;    using tiid = tuple<int, int, ld>;
using tili = tuple<int, ll, int>;     using till = tuple<int, ll, ll>;     using tild = tuple<int, ll, ld>;
using tidi = tuple<int, ld, int>;     using tidl = tuple<int, ld, ll>;     using tidd = tuple<int, ld, ld>;
using tlii = tuple<ll, int, int>;     using tlil = tuple<ll, int, ll>;     using tlid = tuple<ll, int, ld>;
using tlli = tuple<ll, ll, int>;      using tlll = tuple<ll, ll, ll>;      using tlld = tuple<ll, ll, ld>;
using tldi = tuple<ll, ld, int>;      using tldl = tuple<ll, ld, ll>;      using tldd = tuple<ll, ld, ld>;
using tdii = tuple<ld, int, int>;     using tdil = tuple<ld, int, ll>;     using tdid = tuple<ld, int, ld>;
using tdli = tuple<ld, ll, int>;      using tdll = tuple<ld, ll, ll>;      using tdld = tuple<ld, ll, ld>;
using tddi = tuple<ld, ld, int>;      using tddl = tuple<ld, ld, ll>;      using tddd = tuple<ld, ld, ld>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
template <typename T> using oi = ostream_iterator<T>;
template <typename T> using ii = istream_iterator<T>;


/* hash */
struct safe_hash {
    // https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (auto& x : a) cin >> x;)
#define readvec1(type, a, n) __AS_PROCEDURE(vector<type> a((n) + 1); copy_n(ii<type>(cin), (n), a.begin() + 1);)

/*******************************************************/

#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219
// #define TOT_TEST_CASE 10000

void dump() {}

void dump_ignore() {}

void prep() {
}

class quick_union {
private:
    vector<size_t> c, sz;
public:
    quick_union(size_t n) : c(n), sz(n) {
        iota(c.begin(), c.end(), 0);
        sz.assign(n, 1);
    }

    size_t query(size_t i) {
        if (c[i] != i) c[i] = query(c[i]);
        return c[i];
    }

    void merge(size_t i, size_t j) {
        if (connected(i, j)) return;
        sz[query(j)] += sz[query(i)];
        c[query(i)] = query(j);
    }
    bool connected(size_t i, size_t j) {
        return query(i) == query(j);
    }
    size_t query_size(size_t i) {
        return sz[query(i)];
    }
};

// __attribute__((target("popcnt")))
void solve() {
    read(int, n, m);
    readvec(int, a, n);
    vector<unordered_map<int, int, safe_hash>> link(n + 1);
    quick_union qu(n + 1);
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            link[a[i - 1]][a[i]] += 1;
            link[a[i]][a[i - 1]] += 1;
            ++res;
        }
    }
    int cnt = 0;
    cout << res << '\n';
    for (int i = 0; i < m - 1; ++i) {
        read(int, u, v);
        u = qu.query(u), v = qu.query(v);
        if (u != v) {
            if (link[u].size() > link[v].size()) {
                swap(u, v);
            }
            for (auto&& [x, c] : link[u]) {
                cnt += 1;
                link[x].erase(u);
                if (x == v) {
                    res -= c;
                } else {
                    link[x][v] += c;
                    link[v][x] += c;
                }
            }
            qu.merge(u, v);
        }
        cout << res << '\n';
    }
    cout << cnt << '\n';
}

int main() {
#if __cplusplus < 201402L or defined(_MSC_VER) and not defined(__clang__)
    assert(false && "incompatible compiler variant detected.");
#endif
    untie;
    prep();
#ifdef SINGLE_TEST_CASE
    solve();
#else
    read(int, t);
    for (int i = 0; i < t; ++i) {
#ifdef DUMP_TEST_CASE
        if (t != (TOT_TEST_CASE)) {
            solve();
        } else if (i + 1 == (DUMP_TEST_CASE)) {
            dump();
        } else {
            dump_ignore();
        }
#else
        solve();
#endif
    }
#endif
}
