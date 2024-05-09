#include <bits/stdc++.h>
using namespace std;

vector<int> effect() {
    cerr << "called.\n";
    vector<int> res(5);
    iota(res.begin(), res.end(), 0);
    return res;
}

int main() {
    for (auto&& i : effect()) {
        cout << i << '\n';
    }
}
