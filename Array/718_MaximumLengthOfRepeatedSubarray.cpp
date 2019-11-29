//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/11/28.
//
#include <vector>

using std::vector;
using std::min;
using std::max;

int findLength(vector<int>& A, vector<int>& B)
{
    int m = A.size();
    int n = B.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = std::max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int find(vector<int>& A, vector<int>& B)
{
    if (A.size() < B.size())
        swap(A, B);

    int m = A.size();
    int n = B.size();
    int ans = 0;
    vector<int> dp(n+1);
    for (int i = 1; i <= m; ++i)
        for (int j = n; j >= 1; --j) {
            dp[j] = A[i-1] == B[j-1] ? dp[j-1] + 1 : 0;
            ans = std::max(ans, dp[j]);
        }

    return ans;

}

typedef long long ll;

class Solution {

public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(), result = 0;
        init(n, m, A, B);
        int l = 1, r = min(n, m);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(n, m, mid)) {
                l = mid + 1;
                result = max(result, mid);
            } else {
                r = mid - 1;
            }
        }

        return result;
    }

private:
    const int mod = 1e9 + 7, seed = 131;
    vector<ll> Pow;
    vector<ll> hashA;
    vector<ll> hashB;
    void init(int n, int m, vector<int>& A, vector<int>& B) {
        Pow = vector(max(n, m), 0LL);
        hashA = vector(n, 0LL);
        hashB = vector(m, 0LL);
        Pow[0] = 1;
        for (int i = 1; i < n || i < m; ++i) {
            Pow[i] = (ll) Pow[i - 1] * seed % mod;
        }
        hashA[0] = A[0], hashB[0] = B[0];
        for (int i = 1; i < n; ++i) {
            hashA[i] = ((ll) hashA[i - 1] * seed + A[i]) % mod;
        }
        for (int i = 1; i < m; ++i) {
            hashB[i] = ((ll) hashB[i - 1] * seed + B[i]) % mod;
        }
    }

    inline ll cal_hash(const int l, const int r, vector<ll> &num) {
        return l == 0 ? num[r] : (num[r] - num[l-1] * Pow[r - l + 1] % mod + mod) % mod;
    }

    bool check(const int n, const int m, const int len) {
        unordered_set<ll> count;
        for (int i = 0; i + len <= n; ++i) {
            ll hash_code = cal_hash(i, i + len - 1, hashA);
            count.insert(hash_code);
        }
        for (int i = 0; i + len <= m; ++i) {
            ll hash_code = cal_hash(i, i + len - 1, hashB);
            if (count.find(hash_code) != count.end()) {
                return true;
            }
        }
        return false;
    }
};
