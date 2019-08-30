//
// Created by neojxwang(王靖煊) on 2019-08-24.
//

#include <vector>

using namespace std;

/**
 * first version
 *
 */
int longestMountain(vector<int>& A)
{
    if (A.size() == 0)
        return 0;

    int n = A.size();
    int len = INT_MIN;
    vector<int> up(n, 0);
    vector<int> down(n, 0);

    for (int i = n-2; i >= 0; --i)
        if (A[i] > A[i+1])
            down[i] = down[i+1] + 1;

    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i-1])
            up[i] = up[i-1] + 1;

        if (up[i] > 0 && down[i] > 0)
            len = max(len, down[i] + up[i] + 1);
    }
    return len;
}

int longestMountain1(vector<int>& A)
{
    int up = 0;
    int down = 0;
    int len = INT_MIN;
    int n = A.size();

    for (int i = 1; i < n; i++)
    {
        if ((down && A[i-1] < A[i]) || A[i-1] == A[i])
            up = down = 0;

        if (A[i-1] < A[i])
            up++;
        if (A[i-1] > A[i])
            down++;

        if (up && down)
            len = max(len, up + down + 1);
    }
    return len;
}

