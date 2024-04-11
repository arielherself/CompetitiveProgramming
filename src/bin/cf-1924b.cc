#pragma GCC optimize("Ofast")
/////////////////////////////////////////////////////////
/**
 * Useful Macros
 *   by subcrip
 * (requires C++17)
 */

#include<bits/stdc++.h>
using namespace std;

/* macro helpers */
#define __NARGS(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value
#define __DECOMPOSE_S(a, x) auto x = a;
#define __DECOMPOSE_N(a, ...) auto [__VA_ARGS__] = a;
constexpr void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()
#define __as_typeof(container) decltype(container)::value_type

/* type aliases */
using ll = int64_t;
using ull = uint64_t;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

/* constants */
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll MDL = 1e9 + 7;
constexpr ll PRIME = 998'244'353;
constexpr ll MDL1 = 8784491;
constexpr ll MDL2 = PRIME;

/* random */

mt19937 rd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

/* bit-wise operations */
#define lowbit(x) ((x) & -(x))
#define popcount(x) (__builtin_popcountll(ll(x)))
#define parity(x) (__builtin_parityll(ll(x)))
#define msp(x) (63LL - __builtin_clzll(ll(x)))
#define lsp(x) (__builtin_ctzll(ll(x)))

/* arithmetic operations */
#define mod(x, y) ((((x) % (y)) + (y)) % (y))

/* fast pairs */
#define upair ull
#define umake(x, y) (ull(x) << 32 | (ull(y) & ((1ULL << 32) - 1)))
#define u1(p) ((p) >> 32)
#define u2(p) ((p) & ((1ULL << 32) - 1))
#define ult std::less<upair>
#define ugt std::greater<upair>

#define ipair ull
#define imake(x, y) (umake(x, y))
#define i1(p) (int(u1(ll(p))))
#define i2(p) (ll(u2(p) << 32) >> 32)
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

/* conditions */
#define loop while (1)
#define if_or(var, val) if (!(var == val)) var = val; else
#define continue_or(var, val) __AS_PROCEDURE(if (var == val) continue; var = val;)
#define break_or(var, val) __AS_PROCEDURE(if (var == val) break; var = val;)

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

struct pair_hash {
    template <typename T, typename U>
    size_t operator()(const pair<T, U>& a) const {
        auto hash1 = safe_hash()(a.first);
        auto hash2 = safe_hash()(a.second);
        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }
        return hash1;
    }
};

/* build data structures */
#define unordered_counter(from, to) __AS_PROCEDURE(unordered_map<__as_typeof(from), size_t, safe_hash> to; for (auto&& x : from) ++to[x];)
#define counter(from, to, cmp) __AS_PROCEDURE(map<__as_typeof(from), size_t, cmp> to; for (auto&& x : from) ++to[x];)
#define pa(a) __AS_PROCEDURE(__typeof(a) pa; pa.push_back({}); for (auto&&x : a) pa.push_back(pa.back() + x);)
#define sa(a) __AS_PROCEDURE(__typeof(a) sa(a.size() + 1); {int n = a.size(); for (int i = n - 1; i >= 0; --i) sa[i] = sa[i + 1] + a[i];};)
#define adj(ch, n) __AS_PROCEDURE(vector<vector<int>> ch((n) + 1);)
#define edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v), ch[v].push_back(u);)
#define Edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v);)
template <typename T, typename Iterator> pair<size_t, map<T, size_t>> discretize(Iterator __first, Iterator __last) {
    set<T> st(__first, __last);
    size_t N = 0;
    map<T, size_t> mp;
    for (auto&& x : st) mp[x] = ++N;
    return {N, mp};
}
template <typename T, typename Iterator> pair<size_t, unordered_map<T, size_t, safe_hash>> unordered_discretize(Iterator __first, Iterator __last) {
    set<T> st(__first, __last);
    size_t N = 0;
    unordered_map<T, size_t, safe_hash> mp;
    for (auto&& x : st) mp[x] = ++N;
    return {N, mp};
}

/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (int i = 0; i < (n); ++i) cin >> a[i];)
#define putvec(a) __AS_PROCEDURE(for (auto&& x : a) cout << x << ' '; cout << endl;)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << (x) << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;)
template<typename T, typename U> ostream& operator<<(ostream& out, const pair<T, U>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}
template<typename Char, typename Traits, typename Tuple, std::size_t... Index>
void print_tuple_impl(std::basic_ostream<Char, Traits>& os, const Tuple& t, std::index_sequence<Index...>) {
    using swallow = int[]; // guaranties left to right order
    (void)swallow { 0, (void(os << (Index == 0 ? "" : ", ") << std::get<Index>(t)), 0)... };
}
template<typename Char, typename Traits, typename... Args>
decltype(auto) operator<<(std::basic_ostream<Char, Traits>& os, const std::tuple<Args...>& t) {
    os << "{";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << "}";
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (auto&& i : vec) out << i << ' ';
    return out;
}

/* pops */
#define poptop(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.top(); q.pop();)
#define popback(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.back(); q.pop_back();)
#define popfront(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.front();q.pop_front();)

/* math */
constexpr inline int lg2(ll x) { return x == 0 ? -1 : sizeof(ll) * 8 - 1 - __builtin_clzll(x); }

void __exgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  __exgcd(b, a % b, y, x);
  y -= a / b * x;
}

ll inverse(ll a, ll b) {
    ll x, y;
    __exgcd(a, b, x, y);
    return mod(x, b);
}

vector<tuple<int, int, ll>> decompose(ll x) {
    vector<tuple<int, int, ll>> res;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            ll pw = 1;
            while (x % i == 0) ++cnt, x /= i, pw *= i;
            res.emplace_back(i, cnt, pw);
        }
    }
    if (x != 1) {
        res.emplace_back(x, 1, x);
    }
    return res;
}

/* string algorithms */
vector<int> calc_next(string t) {  // pi function of t
  int n = (int)t.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && t[i] != t[j]) j = pi[j - 1];
    if (t[i] == t[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> calc_z(string t) {  // z function of t
    int m = t.length();
    vector<int> z;
    z.push_back(m);
    pair<int, int> prev = {1, -1};
    for (int i = 1; i < m; ++i) {
        if (z[i - prev.first] + i <= prev.second) {
            z.push_back(z[i - prev.first]);
        } else {
            int j = max(i, prev.second + 1);
            while (j < m && t[j] == t[j - i]) ++j;
            z.push_back(j - i);
            prev = {i, j - 1};
        }
    }
    return z;
}
vector<int> kmp(string s, string t) {  // find all t in s
  string cur = t + '#' + s;
  int sz1 = s.size(), sz2 = t.size();
  vector<int> v;
  vector<int> lps = calc_next(cur);
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2) v.push_back(i - 2 * sz2);
  }
  return v;
}
int period(string s) {  // find the length of shortest recurring period
    int n = s.length();
    auto z = calc_z(s);
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0 && z[i] == n - i) {
            return i;
        }
    }
    return n;
}
/////////////////////////////////////////////////////////

#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 512

void dump() {}

void prep() {}

template<typename Addable_Info_t, typename Tag_t, typename Sequence = std::vector<Addable_Info_t>> class segtree {
private:
    using size_type = uint64_t;
    using info_type = Addable_Info_t;
    using tag_type = Tag_t;
    size_type _max;
    vector<info_type> d;
    vector<tag_type> b;

    void pull(size_type p) {
        d[p] = d[p * 2] + d[p * 2 + 1];
    }

    void push(size_type p, size_type left_len, size_type right_len) {
        d[p * 2].apply(b[p], left_len), d[p * 2 + 1].apply(b[p], right_len);
        b[p * 2].apply(b[p]), b[p * 2 + 1].apply(b[p]);
        b[p] = tag_type();
    }

    void set(size_type s, size_type t, size_type p, size_type x, const info_type& c) {
        if (s == t) {
            d[p] = c;
            return;
        }
        size_type m = s + (t - s >> 1);
        if (s != t) push(p, m - s + 1, t - m);
        if (x <= m) set(s, m, p * 2, x, c);
        else set(m + 1, t, p * 2 + 1, x, c);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }
    
    void range_apply(size_type s, size_type t, size_type p, size_type l, size_type r, const tag_type& c) {
        if (l <= s && t <= r) {
            d[p].apply(c, t - s + 1);
            b[p].apply(c);
            return;
        }
        size_type m = s + (t - s >> 1);
        push(p, m - s + 1, t - m);
        if (l <= m) range_apply(s, m, p * 2, l, r, c);
        if (r > m)  range_apply(m + 1, t, p * 2 + 1, l, r, c);
        pull(p);
    }

    info_type range_query(size_type s, size_type t, size_type p, size_type l, size_type r) {
        if (l <= s && t <= r) {
            return d[p];
        }
        size_type m = s + (t - s >> 1);
        info_type res = {};
        push(p, m - s + 1, t - m);
        if (l <= m) res = res + range_query(s, m, p * 2, l, r);
        if (r > m)  res = res + range_query(m + 1, t, p * 2 + 1, l, r);
        return res;
    }

    void build(const Sequence& a, size_type s, size_type t, size_type p) {
        if (s == t) {
            d[p] = a[s];
            return;
        }
        int m = s + (t - s >> 1);
        build(a, s, m, p * 2);
        build(a, m + 1, t, p * 2 + 1);
        pull(p);
    }
public:
    segtree(size_type __max) : d(4 * __max), b(4 * __max), _max(__max - 1) {}
    segtree(const Sequence& a) : segtree(a.size()) {
        build(a, {}, _max, 1);
    }

    void set(size_type i, const info_type& c) {
        set({}, _max, 1, i, c);
    }
    
    void range_apply(size_type l, size_type r, const tag_type& c) {
        range_apply({}, _max, 1, l, r, c);
    }

    void apply(size_type i, const tag_type& c) {
        range_apply(i, i, c);
    }

    info_type range_query(size_type l, size_type r) {
        return range_query({}, _max, 1, l, r);
    }

    info_type query(size_type i) {
        return range_query(i, i);
    }

    Sequence serialize() {
        Sequence res = {};
        for (size_type i = 0; i <= _max; ++i) {
            res.push_back(query(i));
        }
        return res;
    }

    const vector<info_type>& get_d() {
        return d;
    }
};

struct Tag {
    ll val = -1;
    void apply(const Tag& rhs) {
        if (rhs.val != -1)
        val = rhs.val;
    }
};

struct Info {
    ll val = 0;
    void apply(const Tag& rhs, size_t len) {
        if (rhs.val != -1)
        val = rhs.val * len;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.val + b.val};
}

void solve() {
    read(int, n, m, q);
    map<int, ll> pts;
    readvec(int, ipt, 2 * m);
    for (int i = 0; i < m; ++i) {
        pts[ipt[i] - 1] = ipt[i + m];
    }
    segtree<Info, Tag> tr(n);
    int prev_idx = pts.begin()->first;
    ll prev_y = pts.begin()->second;
    for (auto&& [x, y] : pts) {
        if (x == prev_idx) {
            continue;
        }
        if (prev_idx + 1 != x) {
            ll t = x - prev_idx - 1;
            tr.set(prev_idx, {t * (t + 1) / 2 * prev_y});
        }
        prev_idx = x, prev_y = y;
    }
    while (q--) {
        read(int, op);
        if (op == 1) {
            read(int, x, y);
            --x;
            auto lb = pts.lower_bound(x);
            auto ub = pts.upper_bound(x);
            if (lb != pts.begin()) {
                auto [prev_x, prev_y] = *--lb;
                ll t = x - prev_x - 1;
                tr.set(prev_x, {t * (t + 1) / 2 * prev_y});
            }
            assert(ub != pts.end());
            if (ub != pts.end()) {
                auto [next_x, next_y] = *ub;
                ll t = next_x - x - 1;
                tr.set(x, {t * (t + 1) / 2 * y});
            }
            pts[x] = y;
        } else {
            read(int, l, r);
            --l, --r;
            auto lb = pts.lower_bound(l);
            auto ub = pts.upper_bound(r);
            assert(lb != pts.end());
            ll res = 0;
            auto [p_x, p_y] = *lb;
            assert(ub != pts.begin());
            auto next_lb = ub;
            --next_lb;
            auto [q_x, q_y] = *next_lb;
            // debug(res);
            if (p_x <= q_x) {
                if (lb != pts.begin()) {
                    auto prev_lb = lb;
                    --prev_lb;
                    ll t = p_x - l;
                    // debug(t);
                    res += t * (t + 1) / 2 * prev_lb->second;
                    // debug(res);
                }
                ll e = ub->first - r, f = ub->first - q_x - 1;
                assert(f - e + 1 >= 0);
                res += (e + f) * (f - e + 1) / 2 * q_y;
                if (p_x <= q_x - 1) {
                    res += tr.range_query(p_x, q_x - 1).val;
                }
            } else {
                // use q?
                ll e = p_x - r, f = p_x - l;
                res += (e + f) * (f - e + 1) / 2 * q_y;
            }
            cout << res << '\n';
        }
    }
}

int main() {
#if __cplusplus < 201703L || defined(_MSC_VER) && !defined(__clang__)
    assert(false && "incompatible compiler variant detected.");
#endif
    untie, cout.tie(NULL);
    prep();
#ifdef SINGLE_TEST_CASE
    solve();
#else
    read(int, t);
    for (int i = 0; i < t; ++i) {
#ifdef DUMP_TEST_CASE
        if (i + 1 == (DUMP_TEST_CASE)) {
            dump();
        } else {
            solve();
        }
#else
        solve();
#endif
    }
#endif
}
