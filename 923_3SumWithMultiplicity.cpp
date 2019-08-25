//
// Created by neojxwang(王靖煊) on 2019-08-25.
//

#include <vector>

using std::vector;

int threeSumMulti(vector<int>& A, int target)
{
    constexpr int mo = 1e9 + 7;
    sort(A.begin(), A.end());
    vector<long> mp(101, 0);
    long res = 0;
    for_each(A.begin(), A.end(), [&](int n){mp[n]++;});

    for (int i = 0; i <= target; i++)
        for (int j = i; j <= target; j++)
        {
            int k = target - j - i;
            if (k < 0 || k >= mp.size() || k < j)
                continue;
            if (!mp[i] || !mp[j] || !mp[k])
                continue;
            if (i == j && j == k)
                res += (mp[i] - 1) * (mp[i] - 2) * mp[i] / 6;
            else if (i == j && j != k)
                res += mp[i] * (mp[i]-1) / 2 * mp[k];
            else if (i != j && j == k)
                res += mp[i] * mp[j] * (mp[j] - 1) / 2;
            else
                res += mp[i] * mp[j] * mp[k];
            res = res % mo;
        }
    return res;
}
