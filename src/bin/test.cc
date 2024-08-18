#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n = 100;
    vector<int> sg(n + 1);
    for (int i = 1; i <= n; ++i) {
        vector<int> has(n + 2);
        for (int j = 1; j <= i; ++j) {
            if (gcd(j, i) == 1) {
                has[sg[j]] = 1;
            }
        }
        for (int j = 0; j < n + 2; ++j) {
            if (not has[j]) {
                sg[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        cout << i << ' ' << sg[i] << '\n';
    }
}
