//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/4.
//

#include <vector>

using std::vector;

int subarraysDivByK(vector<int>& A, int K)
{
    const int n = A.size();
    int ans = 0;
    vector<int> pre(n+1, 0);

    for (int i = 0; i < n; ++i)
        pre[i+1] = pre[i] + A[i];

    vector<int> mp(K, 0);

    for (auto i : pre)
        mp[((i % K) + K) % K]++;

    for (auto i : mp)
        if (i > 1)
            ans += i * (i - 1) / 2;

    return ans;
}


int subarraysDivByKII(vector<int>& A, int K)
{
    vector<int> sum(K, 0);
    const int n = A.size();
    int tmp = 0;
    int ans = 0;
    sum[0] = 1;
    for (int i = 0; i < n; ++i) {
        tmp = (tmp + A[i] % K + K) % K;
        ans += sum[tmp]++;
    }
    return ans;
}

