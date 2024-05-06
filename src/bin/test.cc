#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> col_pos(n, vector<int>(n + 1)), col_neg(n, vector<int>(n + 1));
        vector<vector<int>> row_pos(n, vector<int>(n + 1)), row_neg(n, vector<int>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                row_pos[i][j] = row_pos[i][j - 1] + (a[i][j - 1] == 1);
                row_neg[i][j] = row_neg[i][j - 1] + (a[i][j - 1] == -1);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                col_pos[i][j] = col_pos[i][j - 1] + (a[j - 1][i] == 1);
                col_neg[i][j] = col_neg[i][j - 1] + (a[j - 1][i] == -1);
            }
        }
        dp[0][0] = (a[0][0] == 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= i; ++k) {
                    for (int l = 0; l <= j; ++l) {
                        if (k == i and l == j) continue;
                        if (row_neg[i][j + 1] - row_neg[i][l] or row_neg[k][j + 1] - row_neg[k][l]) continue;
                        if (col_neg[l][i + 1] - col_neg[l][k] or col_neg[j][i + 1] - col_neg[j][k]) continue;
                        if (k == i) {
                            dp[i][j] = max(dp[i][j], dp[k][l] + row_pos[i][j + 1] - row_pos[i][l + 1]);
                        } else if (l == j) {
                            dp[i][j] = max(dp[i][j], col_pos[j][i + 1] - col_pos[j][k + 1]);
                        } else {
                            dp[i][j] = max(dp[i][j], dp[k][l] + row_pos[k][j + 1] - row_pos[k][l] + col_pos[j][i + 1] - col_pos[j][k] + row_pos[i][j + 1] - row_pos[i][l] + col_pos[l][i + 1] - col_pos[l][k ] - 2 * (a[k][l] == 1) - (a[k][j] == 1) - (a[i][j] == 1) - (a[i][l] == 1));
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cerr << dp[i][j] << " \n"[j + 1 == n];
        //     }
        // }
        return dp[n - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    cout << Solution().cherryPickup(grid);
}
