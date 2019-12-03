//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/2.
//

#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::map;
using std::max;
using std::unordered_map;

int lenLongest(vector<int>& A)
{
    const int n = A.size();
    sort(begin(A), end(A));
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ans = 0;

    for (int j = 0; j < n; ++j)
        for (int k = j+1; k < n; ++k) {
            int a_i = A[k] - A[j];
            if (a_i >= A[j])
                break;
            auto it = lower_bound(begin(A), end(A), a_i);
            if (it == end(A))
                continue;
            int i = it - begin(A);
            if (A[i] != a_i)
                continue;
            dp[j][k] = dp[i][j] + 1;
            ans = max(ans, dp[j][k]);
        }
    return ans;
}

int lenLongestSubarray(vector<int>& A)
{
    int dp[1000][1000] = {};
    unordered_map<int, int> m;
    std::ios::sync_with_stdio(false);
    long long res = 0, upper = A[A.size() - 1], sz = A.size();
    for(int i = 0; i < A.size(); i++){
        m[A[i]] = i+1;
    }
    for(int i = 1; i < sz; i++){
        for(int j = i + 1; j <= sz && (res - 2)*A[j - 1] <= upper; j++){
            long long f1 = A[i - 1], f2 = A[j - 1], count = 2;
            if(dp[i][j] == 1 || m.count(f1+f2) == 0) continue;
            while(m.count(f1+f2)){
                int tmp = f2;
                f2 = f1 + f2;
                f1 = tmp;
                dp[m[f1]][m[f2]] = 1;
                count++;
            }
            if(count > 2)
                res = max(res, count);
        }
    }
    return res;
}

int lenLongestSubarrayHashtable(vector<int>& A)
{
    unordered_map<int, int> mp;
    const int n = A.size();
    int ans = 0;

    for (int i = 0; i < n; ++i)
        mp[A[i]] = i;

    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) {
            int a = A[i];
            int b = A[j];
            int c = a + b;
            int l = 2;

            while (mp.count(c)) {
                l++;
                a = b;
                b = c;
                c = a + b;
            }
            ans = max(ans, l);
        }
    return ans == 2 ? 0 : ans;



}
