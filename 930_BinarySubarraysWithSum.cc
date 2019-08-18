//
// Created by neojxwang(王靖煊) on 2019-08-08.
//

#include <vector>

using std::vector;

int getBinarySum(vector<int>& A, int S)
{
    int left = 0, cnt = 0, n = A.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += A[i];
        while (cnt > S)
            cnt -= A[left++];

        if (cnt == S)
            ans++;
        if (cnt < S)
            continue;

        int t = left;
        while (t < i && A[t] == 0)
        {
            t++;
            ans++;
        }
    }
    return ans;
}

