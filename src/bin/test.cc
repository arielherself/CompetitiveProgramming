#include<bits/stdc++.h>

using namespace std;

typedef long long LL;



int main (){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, x; cin >> n >> x;
    
    vector<int> a(n); 
    for(int& i : a) cin >> i;
    vector<int> t(n);
    auto cal = [&](){
     vector<int> dp(x + 1, 1e9);
     dp[0] = 0;
     for(int i : t)
      for(int j = x; j >= i; j --)
       dp[j] = min(dp[j], dp[j - i] + 1);
     return dp[x];
    };
    int res = 1e9;
    for(int i = 0; i < n; i ++)
    {
     for(int j = 0; j < n; j ++)
      t[j] = a[j] / 2;
     t[i] = a[i];
     res = min(res, cal());
    }

    if(res == int(1e9))
        cout << -1 << "\n";
    else
        cout << res << "\n";
    return 0;
}
