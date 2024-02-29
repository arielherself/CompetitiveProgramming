#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define Abdoo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void pr(vector<long long> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<long long> get_divs(long long n){
    vector<long long> divs;
    for(long long i=1; i*i <=n; i++){
        if(n%i == 0) {
            divs.push_back(i);
            if(i != n/i) divs.push_back(n/i);
        }
    }
    return  divs;
}

int main() {
    Abdoo
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int a,b,l,cnt =0;
        cin >> a >> b >> l;
        vector<long long> v = get_divs(l);
        sort(v.begin(),v.end());
        //pr(v);
        set<int> st;
        for(int i = 0; i < v.size(); i++){
            long long ax = 1;
            for(int j = 0; j < 21; j++){
                long long bx = 1;
                ax *= a;
                if(j == 0) ax = 1;
                for(int k =0; k < 21; k++){
                    bx *= b;
                    if(k == 0) bx = 1;
                    long long x = v[i] * ax * bx;

                    if(l == x){
                        //cout << x << " " << v[i] << " " << j << " " << k << "\n";
                        st.insert(v[i]);
                    }
                    if(b == 1 || bx >= 2e6){
                        break;
                    }
                }
                if(a == 1 || ax >= 2e6){
                    break;
                }
            }
        }
        cout << st.size() << "\n";
    }
    return 0;
}
