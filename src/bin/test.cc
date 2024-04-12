#include <bits/stdc++.h>
using namespace std;

int main() {
    cerr << gcd(0, 1) << '\n';;
    assert(gcd(0, 1) == 0);
    assert(gcd(0, 2) == 0);
    assert(gcd(0, 10) == 0);
    assert(gcd(1, 0) == 0);
    assert(gcd(2, 0) == 0);
    assert(gcd(10, 0) == 0);
}
