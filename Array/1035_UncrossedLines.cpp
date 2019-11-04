//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-04.
//
#include <vector>

using std::vector;

int maxUncrossedLines(vector<int>& A, vector<int>& B)
{
    const int n = A.size();
    const int m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }

    return dp[n][m];
}

