# void solve() {
#     read(ll, n, k, q);
#     vector<ll> a(k + 1), b(k + 1);
#     for (int i = 1; i <= k; ++i) cin >> a[i];
#     for (int i = 1; i <= k; ++i) cin >> b[i];
#     while (q--) {
#         read(ll, d);
#         int l = 0, r = k;
#         while (l < r) {
#             int mid = l + r + 1 >> 1;
#             if (a[mid] <= d) {
#                 l = mid;
#             } else {
#                 r = mid - 1;
#             }
#         }
#         
#         if (a[l] == d) {
#             cout << b[l] << ' ';
#         } else {
#             ll res = double(1) * (d - a[l]) / (a[l + 1] - a[l]) * (b[l + 1] - b[l]);
#             cout << b[l] + res << ' ';
#         }
#     }
#     cout << endl;
# }

import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    k = int(input())
    q = int(input())
    a = [0] * (k + 1)
    b = [0] * (k + 1)
    for _ in range(q):
        d = int(input())
        l = 0
        r = k
        while l < r:
            mid = l + r + 1 >> 1
            if a[mid] <= d:
                l = mid
            else:
                r = mid - 1
        if a[l] == d:
            print(b[l], end=' ')
        else:
            res = (d - a[l]) / (a[l + 1] - a[l]) * (b[l + 1] - b[l])
            print(b[l] + res)
