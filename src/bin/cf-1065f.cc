// #pragma GCC target("popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC optimize("Ofast")
/************* This code requires C++17. ***************/

#include<bits/stdc++.h>
using namespace std;

/* macro helpers */
#define __NARGS(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value
#define __DECOMPOSE_S(a, x) auto x = a;
#define __DECOMPOSE_N(a, ...) auto [__VA_ARGS__] = a;
constexpr void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()
#define __as_typeof(container) remove_reference<decltype(container)>::type

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

/* constants */
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll MDL = 1e9 + 7;
constexpr ll PRIME = 998'244'353;
constexpr ll MDL1 = 8784491;
constexpr ll MDL2 = PRIME;
constexpr int128 INT128_MAX = numeric_limits<int128>::max();
constexpr uint128 UINT128_MAX = numeric_limits<uint128>::max();
constexpr int128 INT128_MIN = numeric_limits<int128>::min();
constexpr uint128 UINT128_MIN = numeric_limits<uint128>::min();

/* random */

mt19937_64 rd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

/* bit-wise operations */
#define lowbit(x) ((x) & -(x))
#define popcount(x) (__builtin_popcountll(ll(x)))
#define parity(x) (__builtin_parityll(ll(x)))
#define msp(x) (63LL - __builtin_clzll(ll(x)))
#define lsp(x) (__builtin_ctzll(ll(x)))

/* arithmetic operations */
#define mod(x, y) ((((x) % (y)) + (y)) % (y))

/* fast pairs */
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

/* build data structures */
#define faster(um) __AS_PROCEDURE((um).reserve(1024); (um).max_load_factor(0.25);)
#define unordered_counter(from, to) __AS_PROCEDURE(unordered_map<__as_typeof(from), size_t, safe_hash> to; for (auto&& x : from) ++to[x];)
#define counter(from, to, cmp) __AS_PROCEDURE(map<__as_typeof(from), size_t, cmp> to; for (auto&& x : from) ++to[x];)
#define pa(a) __AS_PROCEDURE(__typeof(a) pa; pa.push_back({}); for (auto&&x : a) pa.push_back(pa.back() + x);)
#define sa(a) __AS_PROCEDURE(__typeof(a) sa(a.size() + 1); {int n = a.size(); for (int i = n - 1; i >= 0; --i) sa[i] = sa[i + 1] + a[i];};)
#define adj(ch, n) __AS_PROCEDURE(vector<vector<int>> ch((n) + 1);)
#define edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v), ch[v].push_back(u);)
#define edgew(ch, u, v, ...) __AS_PROCEDURE(ch[u].emplace_back(v, __VA_ARGS__), ch[v].emplace_back(u, __VA_ARGS__);)
#define Edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v);)
#define Edgew(ch, u, v, ...) __AS_PROCEDURE(ch[u].emplace_back(v, __VA_ARGS__);)

/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T, typename U> istream& operator>>(istream& in, pair<T, U>& p) {
    return in >> p.first >> p.second;
}
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
std::ostream& operator<<(std::ostream& dest, const int128& value) {
    // https://stackoverflow.com/a/25115163/23881100
    std::ostream::sentry s( dest );
    if ( s ) {
        uint128 tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (auto& x : a) cin >> x;)
#define readvec1(type, a, n) __AS_PROCEDURE(vector<type> a((n) + 1); copy_n(ii<type>(cin), (n), a.begin() + 1);)
#define putvec(a) __AS_PROCEDURE(copy(a.begin(), a.end(), oi<__as_typeof(a)::value_type>(cout, " ")); cout << endl;)
#define putvec1(a) __AS_PROCEDURE(copy(a.begin() + 1, a.end(), oi<__as_typeof(a)::value_type>(cout, " ")); cout << endl;)
#define putvec_eol(a) __AS_PROCEDURE(copy(a.begin(), a.end(), oi<__as_typeof(a)::value_type>(cout, "\n"));)
#define putvec1_eol(a) __AS_PROCEDURE(copy(a.begin() + 1, a.end(), oi<__as_typeof(a)::value_type>(cout, "\n"));)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << (x) << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;)
#define deb(...) debug(make_tuple(__VA_ARGS__))

/* pops */
#define poptop(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.top(); q.pop();)
#define popback(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.back(); q.pop_back();)
#define popfront(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.front();q.pop_front();)

/* math */

/* string algorithms */

// miscancellous
template <typename T, typename U>
bool chmax(T& lhs, const U& rhs) {
    bool ret = lhs < rhs;
    if (ret) {
        lhs = rhs;
    }
    return ret;
}
template <typename T, typename U>
bool chmin(T& lhs, const U& rhs) {
    bool ret = lhs > rhs;
    if (ret) {
        lhs = rhs;
    }
    return ret;
}

/*******************************************************/

#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219
// #define TOT_TEST_CASE 10000

void dump() {}

void dump_ignore() {}

void prep() {
}

struct Tag {
    int val;
    Tag() : val(INF) {}
    Tag(int val) : val(val) {}
    void apply(const Tag& rhs) {
        chmin(val, rhs.val);
    }
};
struct Info {
    int val;
    Info() : val(INF) {}
    Info(int val) : val(val) {}
    void apply(const Tag& rhs, size_t len) {
        chmin(val, rhs.val);
    }
};
Info operator+(const Info &a, const Info &b) {
    return {min(a.val, b.val)};
}

struct node_info {
    int father, depth, hson, size, head, dfn;
};

constexpr int N = 1e6 + 10;
int st[N], cnt[N], dp[N], to[N], seq[N];
int sz[N];
int dfn[N];
int depth[N];
Info d[N << 2];
Tag b[N << 2];
vector<int> ch[N];
int idx[N];
int n;
int st_sz;
int seq_sz;

template<typename Addable_Info_t, typename Tag_t, typename Sequence = std::vector<Addable_Info_t>> class segtree {
private:
    using size_type = uint64_t;
    using info_type = Addable_Info_t;
    using tag_type = Tag_t;
    size_type _max;
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
        pull(p);
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
    segtree(size_type __max) : _max(__max - 1) {}
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

int k;
int t;

void dfs0(int v, int pa) {
    dfn[v] = t++;
    seq[seq_sz++] = v;
    depth[v] = depth[pa] + 1;
    sz[v] = 1;
    for (auto&& u : ch[v]) {
        if (u == pa) continue;
        dfs0(u, v);
        sz[v] += sz[u];
    }
}

void dfs1(int v, int pa) {
    st[st_sz++] = v;
    to[v] = st[max(0, st_sz - 1 - k)];
    for (auto&& u : ch[v]) {
        if (u == pa) continue;
        dfs1(u, v);
    }
    --st_sz;
}

void dfs2(int v, int pa) {
    for (auto&& u : ch[v]) {
        if (u == pa) continue;
        dfs2(u, v);
    }
    int m = cnt[v];
    for (auto&& u : ch[v]) {
        if (u == pa) continue;
        chmax(dp[v], dp[u] + m);
    }
}

// __attribute__((target("popcnt")))
void solve() {
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        read(int, j);
        edge(ch, i, j);
    }

    dfs0(1, 0);

    iota(idx, idx + n, 1);
    sort(idx, idx + n, [&] (int i, int j) {
        return depth[i] < depth[j];
    });

    dfs1(1, 0);

    segtree<Info, Tag> tr(n);

    for (int i = 0; i < n; ++i) {
        int v = idx[i];
        tr.apply(dfn[v], { dfn[v] });
        if (ch[v].size() == 1 and v != 1) {
            // `v` is a leaf
            int u = to[v];
            // deb(i, v, to, u);
            int back = tr.range_query(dfn[u], dfn[u] + sz[u] - 1).val;
            tr.apply(dfn[v], { back });
            cnt[seq[back]] += 1;
        }
    }

    dfs2(1, 0);

    cout << dp[1] << '\n';
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
