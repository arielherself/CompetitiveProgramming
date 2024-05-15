#include <bits/stdc++.h>
using namespace std;

int main() {
    int m = 4;
    auto rev = [&] (const vector<int>& x) {
        vector<int> res(m + 1);
        for (int i = 0; i < m; ++i) {
            int curr = x[i];
            res[curr] = i + 1;
        }
        return res;
    };
    auto res = rev({2, 1, 3, 4});
    for (auto&& x : res)cout << x << endl;
}
