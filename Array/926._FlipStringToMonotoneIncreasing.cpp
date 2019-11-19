//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-10.
//

#include <vector>

using std::vector;
using std::string;
using std::min;

int minFlipsMonoIncr(string S)
{
    int n = S.size();
    vector<int> l(n+1, 0);
    vector<int> r(n+1, 0);

    l[0] = S[0] == '1';
    for (int i = 1; i < n; ++i)
        l[i] = l[i-1] + (S[i] == '1');

    r[n-1] = S[n-1] == '0';
    for (int i = n-2; i >= 0; --i)
        r[i] = r[i+1] + (S[i] == '0');

    int res = r[0];
    for (int i = 1; i <= n; i++)
        res = std::min(l[i-1] + r[i], res);
    return res;
}

int minFlipsMonoIncr1(string S)
{
    int n = S.size();
    vector<vector<int>> dp(n+1, vector<int>(2));

    dp[0][0] = S[0] == '1';
    dp[0][1] = S[1] == '0';
    for (int i = 1; i <= n; ++i) {
        if (S[i] == '0') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
        } else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    return min(dp[n][0], dp[n][1]);
}

int minFlipsMonoIncr2(string S)
{
    int n = S.size();
    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[0][0] = S[0] == '1';
    dp[0][1] = S[1] == '0';
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + (S[i] == '1');
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (S[i] == '0');
    }
    return min(dp[n][0], dp[n][1]);
}

int minFlipsMonoIncr3(string S)
{
    int n = S.size();
    int dp0 = S[0] == '1';
    int dp1 = S[0] == '0';

    for (int i = 1; i <= n; ++i) {
        int tmp0 = dp0 + (S[i] == '1');
        dp1 = min(dp0, dp1 + (S[i] == '0'));
        dp0 = tmp0;
    }
    return min(dp0, dp1);
}
