#include<bits/stdc++.h>
using namespace std;

#define mod(x, y) (((x) % (y) + (y)) % (y))
using ll = int64_t;
constexpr ll prime = 1e9 + 7;
constexpr ll b1 = 825;
constexpr ll b2 = 87825;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<ll> pa1(n + 1), pa2(n + 1);
        ll hash1 = 0, hash2 = 0;
        for (int i = 1; i <= n; ++i) {
            hash1 = (hash1 * b1 + s[i - 1]) % prime;
            hash2 = (hash2 * b2 + s[i - 1]) % prime;
            pa1[i] = hash1;
            pa2[i] = hash2;
        }
        vector<ll> sa1(n + 1), sa2(n + 1);
        hash1 = 0, hash2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            hash1 = (hash1 * b1 + s[i]) % prime;
            hash2 = (hash2 * b2 + s[i]) % prime;
            sa1[i] = hash1;
            sa2[i] = hash2;
        }
        vector<ll> p1(n + 1), p2(n + 1);
        p1[0] = 1, p2[0] = 1;
        for (int i = 1; i < n; ++i) {
            p1[i] = (p1[i - 1] * b1) % prime;
            p2[i] = (p2[i - 1] * b2) % prime;
        }
        function<bool(int, int)> check_palindrome = [&] (int l, int r) {
            int p = l + r >> 1, q = l + r + 1 >> 1;
            return mod((pa1[p + 1] - pa1[l] * p1[p + 1 - l]), prime) == mod((sa1[q] - sa1[r + 1] * p1[r + 1 - q]), prime) &&
                   mod((pa2[p + 1] - pa2[l] * p2[p + 1 - l]), prime) == mod((sa2[q] - sa2[r + 1] * p2[r + 1 - q]), prime);
        };
        int l = 0;
        pair<int, int> res;
        for (int i = 0; i < n; ++i) {
            l = max(0, l - 1);
            while (!check_palindrome(l, i)) ++l;
            res = max(res, {i - l + 1, l});
        }
        return s.substr(res.second, res.first);
    }
};

int main() {
    string s; cin >> s;
    cout << Solution().longestPalindrome(s);
}