// #pragma GCC target("popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC optimize("Ofast,unroll-loops")
/************* This code requires C++17. ***************/

#include<bits/stdc++.h>
#include<tr2/dynamic_bitset>
using namespace std;

/* macro helpers */
#define __NARGS(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value
#define __DECOMPOSE_S(a, x) auto x = a;
#define __DECOMPOSE_N(a, ...) auto [__VA_ARGS__] = a;
void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()
#define __as_typeof(container) remove_reference<decltype(container)>::type
template <typename T> struct argument_type;
template <typename T, typename U> struct argument_type<T(U)> { using type = U; };
#define always_inline __attribute__((always_inline))

/* type aliases */
#if LONG_LONG_MAX != INT64_MAX
using ll = int64_t;
using ull = uint64_t;
#else
using ll = long long;
using ull = unsigned long long;
#endif

/* constants */
constexpr ll MDL = 1e9 + 7;

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
#define if_or(var, val) if (!((var) == (val))) (var) = (val); else
#define continue_or(var, val) __AS_PROCEDURE(if ((var) == (val)) continue; (var) = (val);)
#define break_or(var, val) __AS_PROCEDURE(if ((var) == (val)) break; (var) = (val);)


/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))

template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(t, ...) __AS_PROCEDURE(argument_type<void(t)>::type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(t, a, n) __AS_PROCEDURE(vector<argument_type<void(t)>::type> a(n); for (auto& x : (a)) cin >> x;)
#define readvec1(t, a, n) __AS_PROCEDURE(vector<argument_type<void(t)>::type> a((n) + 1); copy_n(ii<argument_type<void(t)>::type>(cin), (n), (a).begin() + 1);)
#define putvec(a) __AS_PROCEDURE(copy((a).begin(), (a).end(), oi<__as_typeof(a)::value_type>(cout, " ")); cout << '\n';)
#define putvec1(a) __AS_PROCEDURE(copy((a).begin() + 1, (a).end(), oi<__as_typeof(a)::value_type>(cout, " ")); cout << '\n';)
#define putvec_eol(a) __AS_PROCEDURE(copy((a).begin(), (a).end(), oi<__as_typeof(a)::value_type>(cout, "\n"));)
#define putvec1_eol(a) __AS_PROCEDURE(copy((a).begin() + 1, (a).end(), oi<__as_typeof(a)::value_type>(cout, "\n"));)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << (x) << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : (a)) cerr << x << ' '; cerr << endl;)
#define deb(...) debug(make_tuple(__VA_ARGS__))

/* math */

template <typename T>
constexpr T mygcd(T a, T b) { return b == 0 ? a : mygcd(b, a % b); }

 void __exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	__exgcd(b, a % b, y, x);
	y -= a / b * x;
}

 ll inverse(ll a, ll b) {
	ll x = 0, y = 0;
	__exgcd(a, b, x, y);
	return mod(x, b);
}


/*******************************************************/

#define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219
// #define TOT_TEST_CASE 10000

void dump() {}

void dump_ignore() {}

constexpr int N = 1e6 + 10;
constexpr int M = MDL;
ll fact[N], factrev[N + 1], s[N + 1];

void prep() {
	fact[0] = factrev[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (fact[i - 1] * i) % M;
	}
	s[0] = 1;
	for (int i = 1; i <= N; ++i) {
		s[i] = s[i - 1] * fact[i - 1] % M;
	}
	factrev[N] = inverse(s[N], M);
	for (int i = N; i; --i) {
		factrev[i - 1] = factrev[i] * fact[i - 1] % M;
	}
	for (int i = 0; i < N; ++i) {
		factrev[i] = factrev[i + 1] * s[i] % M;
	}
}

always_inline ll mycomb(int n, int k) {
	if (n < 0 or k < 0 or n < k) return 0;
	return fact[n] * factrev[k] % M * factrev[n - k] % M;
}

/**
 * My thought process
 */

// __attribute__((target("popcnt")))
void solve() {
	read(int, n, k);

	vector<ll> pp(n + 1);
	pp[0] = 2;
	for (int i = 1; i <= n; ++i) {
		pp[i] = pp[i - 1] * pp[i - 1] % M;
	}

	vector<ll> f(n + 1);
	for (int i = k; i <= n; ++i) {
		f[i] = mycomb(n, i) * (pp[n - i] - 1) % M;
	}

	ll res = 0;
	for (int i = k; i <= n; ++i) {
		res = mod(res + ((i - k) % 2 ? -1 : 1) * mycomb(i, k) * f[i] % M, M);
	}

	cout << res << '\n';
}

#ifdef SINGLE_TEST_CASE
#warning: Will run single test case
#else
#warning: Will run multiple test cases
#endif

int main() {
#if __cplusplus < 201402L or defined(_MSC_VER) and not defined(__clang__)
	// static_assert(false, "incompatible compiler variant detected.");
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
