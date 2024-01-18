#include<bits/stdc++.h>
using namespace std;
using ull = uint64_t;
int main() {
    ull l1 = 1, l2 = 1;
    cout << "1, 1";
    for (int i = 2; i <= 1e5 + 1; ++i) {
        ull t = l1 + l2;
        cout << ", " << t;
        l1 = l2;
        l2 = t;
    }
}