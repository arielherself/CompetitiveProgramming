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

// #define SINGLE_TEST_CASE
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

    void push(size_type p) {
        d[p * 2].apply(b[p]), d[p * 2 + 1].apply(b[p]);
        b[p * 2].apply(b[p]), b[p * 2 + 1].apply(b[p]);
        b[p] = tag_type();
    }

    void set(size_type s, size_type t, size_type p, size_type x, const info_type& c) {
        if (s == t) {
            d[p] = c;
            return;
        }
        size_type m = s + (t - s >> 1);
        if (s != t) push(p);
        if (x <= m) set(s, m, p * 2, x, c);
        else set(m + 1, t, p * 2 + 1, x, c);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }
    
    void range_apply(size_type s, size_type t, size_type p, size_type l, size_type r, const tag_type& c) {
        if (l <= s && t <= r) {
            d[p].apply(c);
            b[p].apply(c);
            return;
        }
        size_type m = s + (t - s >> 1);
        push(p);
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
        push(p);
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

struct Set_Tag {
    int val = -2;
    void apply(const Set_Tag& rhs) {
        if (rhs.val != -2)
        val += rhs.val;
    }
};

struct Set_Info {
    int val = 0;
    void apply(const Set_Tag& rhs) {
        if (rhs.val != -2)
        val += rhs.val;
    }
};

Set_Info operator+(const Set_Info &a, const Set_Info &b) {
    return { max(a.val, b.val) };
}
void solve() {
    read(int, n, m);
    adj(ch, n);
    while (m--) {
        read(int, u, v);
        edge(ch, u, v);
    }
    segtree<Set_Info, Set_Tag> tr(n + 1);
    vector<int> dfn(n + 1, -1);
    vector<int> sz(n + 1);
    int tm = 0;
    auto dfs = [&] (auto dfs, int v, int pa) -> bool {
        if (dfn[v] != -1) {
            if (tr.range_query(dfn[v], tm)) {
                // TODO: output
                return true;
            }
        }
        dfn[v] = ++tm;
        tr.set(dfn[v], { sz[v] });
        for (auto&& u : ch[v]) {
            if (u == pa) continue;
            if (dfn[u] == -1) continue;
            sz[v] -= 1;
            tr.apply(dfn[v], {-1});
            sz[u] -= 1;
            tr.apply(dfn[u], {-1});
        }
        for (auto&& u : ch[v]) {
            if (u == pa) continue;
            if (dfs(dfs, u, v)) return true;
        }
        dfn[v] = 0;
        --tm;
        return false;
    };
}

int main() {
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
