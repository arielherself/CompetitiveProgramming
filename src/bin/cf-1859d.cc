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
constexpr ull MDL = 1e9 + 7;
constexpr ull PRIME = 998'244'353;
constexpr ull MDL1 = 825;
constexpr ull MDL2 = 87825;

/* bit-wise operations */
#define lowbit(x) ((x) & -(x))
#define popcount(x) (__builtin_popcountll(ll(x)))
#define parity(x) (__builtin_parityll(ll(x)))
#define msp(x) (63LL - __builtin_clzll(ll(x)))
#define lsp(x) (__builtin_ctzll(ll(x)))

/* arithmetic operations */
#define mod(x, y) (((x) + (y)) % (y))

/* fast pairs */
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

/* conditions */
#define loop while (1)
#define if_or(var, val) if (!(var == val)) var = val; else
#define continue_or(var, val) __AS_PROCEDURE(if (var == val) continue; var = val;)
#define break_or(var, val) __AS_PROCEDURE(if (var == val) break; var = val;)

/* build data structures */
#define unordered_counter(from, to) __AS_PROCEDURE(unordered_map<__as_typeof(from), size_t> to; for (auto&& x : from) ++to[x];)
#define counter(from, to, cmp) __AS_PROCEDURE(map<__as_typeof(from), size_t, cmp> to; for (auto&& x : from) ++to[x];)
#define pa(a) __AS_PROCEDURE(__typeof(a) pa; pa.push_back({}); for (auto&&x : a) pa.push_back(pa.back() + x);)
#define sa(a) __AS_PROCEDURE(__typeof(a) sa(a.size() + 1); {int n = a.size(); for (int i = n - 1; i >= 0; --i) sa[i] = sa[i + 1] + a[i];};)
#define adj(ch, n) __AS_PROCEDURE(vector<vector<int>> ch((n) + 1);)
#define edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v), ch[v].push_back(u);)
#define Edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v);)

/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (int i = 0; i < (n); ++i) cin >> a[i];)
#define putvec(a) __AS_PROCEDURE(for (auto&& x : a) cout << x << ' '; cout << endl;)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << (x) << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;)
template<typename T> ostream& operator<<(ostream& out, vector<T> vec) {
    for (auto&& i : vec) out << i << ' ';
    return out;
}

/* pops */
#define poptop(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.top(); q.pop();)
#define popback(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.back(); q.pop_back();)
#define popfront(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.front();q.pop_front();)

/* algorithms */

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

constexpr int MAXN=2e5+10;
int b[4*MAXN];  // tree d, tags b

int getsum(int s,int t,int p,int l,int r){
    if(l<=s&&t<=r)return b[p];
    int m=s+(t-s>>1),sum=0;
    if(b[p]){
        b[p*2]=b[p],b[p*2+1]=b[p];
        b[p]=0;
    }
    if(l<=m)sum+=getsum(s,m,p*2,l,r);
    if(r>m) sum+=getsum(m+1,t,p*2+1,l,r);
    return sum;
}

void update(int s,int t,int p,int l,int r,int c) {  // difference c
    if(l<=s&&t<=r){
        b[p]=c;
        return;
    }
    int m=s+(t-s>>1);
    if(b[p]&&s!=t){
        b[p*2]=b[p],b[p*2+1]=b[p];
        b[p]=0;
    }
    if(l<=m)update(s,m,p*2,l,r,c);
    if(r>m) update(m+1,t,p*2+1,l,r,c);
}

struct segment {
    ll l, r, a, b, f;
};

void clear(int n) {
    int limit = n + 1;
    memset(b, 0, 4 * limit * sizeof(int));
}

void solve() {
    read(int, n);
    vector<segment> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
    auto cmp_b_greater = [&] (const segment& a, const segment& b) {
        return a.b > b.b;
    };
    auto cmp_l_less = [&] (const segment& a, const segment& b) {
        return a.l < b.l;
    };
    auto cmp_f_less = [&] (const segment& a, const segment& b) {
        return a.f < b.f;
    };
    sort(a.begin(), a.end(), cmp_b_greater);
    priority_queue<segment, vector<segment>, decltype(cmp_f_less)> pq(cmp_f_less);
    for (int i = 0; i < n; ++i) {
        while (pq.size() && pq.top().l > a[i].b) pq.pop();
        a[i].f = a[i].b;
        if (pq.size()) a[i].f = max(a[i].f, pq.top().f);
        pq.push(a[i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     printf("a[%d]: l = %ld, r = %ld, a = %ld, b = %ld, f = %ld\n", i, a[i].l, a[i].r, a[i].a, a[i].b, a[i].f);
    // }
    sort(a.begin(), a.end(), cmp_l_less);
    read(int, q);
    clear(q);
    readvec(ll, query, q);
    vector<int> mp(q);
    iota(mp.begin(), mp.end(), 0);
    sort(mp.begin(), mp.end(), [&] (int i, int j) {return query[i] < query[j];});
    auto find_left = [&] (int bound) {
        int l = 0, r = q - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (query[mp[mid]] < bound) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (query[mp[l]] < bound) {
            return -1;
        }
        return l;
    };
    auto find_right = [&] (int bound) {
        int l = 0, r = q - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (query[mp[mid]] > bound) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (query[mp[l]] > bound) {
            return -1;
        }
        return l;
    };
    for (int i = 0; i < n; ++i) {
        int left = find_left(a[i].l);
        int right = find_right(a[i].r);
        if (left == -1 || right == -1) continue;
        // debug(left), debug(right);
        update(1, q, 1, left + 1, right + 1, a[i].f);
    }
    // for (int i = 0; i < q; ++i) {debug(getsum(1, q, 1, i + 1, i + 1));}
    vector<int> res(q);
    for (int i = 0; i < q; ++i) {
        res[mp[i]] = max(query[mp[i]], ll(getsum(1, q, 1, i + 1, i + 1)));
    }
    putvec(res);
}

int main() {
    untie;
    read(int, t);
    while (t--) solve();
}