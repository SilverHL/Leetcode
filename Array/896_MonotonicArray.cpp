//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-25.
//

#include <vector>

using std::vector;

bool isMonotonic(vector<int>& A)
{
    if (A.empty() || A.size() == 1)
        return true;

    int i = 0;
    int n = A.size();
    int desc = 0;
    int incr = 0;

    for ( ; i < n-1; i++)
    {
        if (A[i] < A[i+1])
            incr++;
        if (A[i] > A[i+1])
            desc++;
    }

    if (incr == n ||
        desc == n)
        return true;
    return false;
}