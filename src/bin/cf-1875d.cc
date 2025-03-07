#include<bits/stdc++.h>
using namespace std;

#define __NARGS(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value
#define __DECOMPOSE_S(a, x) auto x = a;
#define __DECOMPOSE_N(a, ...) auto [__VA_ARGS__] = a;
constexpr void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()
#define __as_typeof(container) decltype(container)::value_type

using ll = int64_t;
using ull = uint64_t;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

constexpr ull MDL = 1e9 + 7;
constexpr ull PRIME = 998244353;
constexpr ull MDL1 = 825;
constexpr ull MDL2 = 87825;

#define lowbit(x) ((x) & -(x))
#define popcount(x) (__builtin_popcountll(ll(x)))
#define parity(x) (__builtin_parityll(ll(x)))
#define msp(x) (63LL - __builtin_clzll(ll(x)))
#define lsp(x) (__builtin_ctzll(ll(x)))

#define upair ull
#define umake(x, y) (ull(x) << 32 | ull(y))
#define u1(p) ((p) >> 32)
#define u2(p) ((p) & ((1ULL << 32) - 1))
#define ult std::less<upair>
#define ugt std::greater<upair>

#define ipair ull
#define imake(x, y) (umake(x, y))
#define i1(p) (int(u1(p)))
#define i2(p) (int(u2(p)))
struct ilt {
    bool operator()(const ipair& a, const ipair& b) const {
        if (i1(a) == i1(b)) return i2(a) < i2(b);
        else return i1(a) < i1(b);
    }
};
struct igt {
    bool operator()(const ipair& a, const ipair& b) const {
        if (i1(a) == i1(b)) return i2(a) > i2(b);
        else return i1(a) > i1(b);
    }
};

#define unordered_counter(from, to) __AS_PROCEDURE(unordered_map<__as_typeof(from), size_t> to; for (auto&& x : from) ++to[x];)
#define counter(from, to, cmp) __AS_PROCEDURE(map<__as_typeof(from), size_t, cmp> to; for (auto&& x : from) ++to[x];)
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (int i = 0; i < (n); ++i) cin >> a[i];)
#define putvec(a) __AS_PROCEDURE(for (auto&& x : a) cout << x << ' '; cout << endl;)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << x << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;)

#define pa(a) __AS_PROCEDURE(__typeof(a) pa; pa.push_back({}); for (auto&&x : a) pa.push_back(pa.back() + x);)
#define sa(a) __AS_PROCEDURE(__typeof(a) sa(a.size() + 1); {int n = a.size(); for (int i = n - 1; i >= 0; --i) sa[i] = sa[i + 1] + a[i];};)

#define poptop(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.top(); q.pop();)
#define popback(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.back(); q.pop_back();)
#define popfront(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.front();q.pop_front();)

#define adj(ch, n) __AS_PROCEDURE(vector<vector<int>> ch((n) + 1);)
#define edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v), ch[v].push_back(u);)
#define Edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v);)

vector<int> kmp(string s, string t) {  // find all t in s
    int n = s.length(), m = t.length();
    vector<int> next; next.push_back(-1);
    int j = -1, i = 0;
    while (i < m)
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            if (i != m && t[i] == t[j]) next.push_back(next[j]);
            else next.push_back(j);
        } else j = next[j];
    vector<int> res;
    i = 0, j = 0;
    while (i < n && j < m)
        if (j == -1 || s[i] == t[j]) {
            ++i, ++j;
            if (j == m) res.push_back(i - j), j = next[j];
        } else j = next[j];
    return res;
}

void solve() {
    read(int, n);
    readvec(int, a, n);
    counter(a, ct, greater<>);
    unordered_map<int, int> res;
    int init = ct.begin()->first + 1;
    int prev = init;
    for (auto&& [i, _] : ct) {
        if (i < prev - 1) {
            init = i + 1;
        }
        prev = i;
    }
    for (auto&& [i, t] : ct) {
        if (i > init) continue;
        int mn = init * int(t - 1) + i;
        for (auto&& [j, prev] : res) {
            mn = min(mn, prev + j * int(t - 1) + i);
        }
        res[i] = mn;
        // debug(i), debug(res[i]);
    }
    cout << res[0] << endl;
}

int main() {
    read(int, t);
    while (t--) solve();
}