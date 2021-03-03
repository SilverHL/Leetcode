#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {

    if (s.empty() || p.empty()) return false;

    int row = s.length();
    int line = p.length();
    vector<vector<bool>> dp(row+1, vector<bool>(line+1, false));

    dp[0][0] = true;

    for (int i = 1; i < line; ++i) {
        if (p[i] == '*' && dp[0][i-1]) {
            dp[0][i+1] = true;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < line; ++j) {
            if (s[i] == p[j] || p[j] == '.') {
                dp[i+1][j+1] = dp[i][j];
            }

            if (p[j] == '*') {
                if (s[i] != p[j-1] && p[j-1] != '.') {
                    dp[i+1][j+1] = dp[i+1][j-1];
                } else {
                    dp[i+1][j+1] = (dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]); 
                }
            }
        }
    }

    return dp[row][line];

}