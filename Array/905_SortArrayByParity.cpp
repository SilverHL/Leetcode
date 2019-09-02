//
// Created by neojxwang(王靖煊) on 2019-08-30.
//

#include <vector>

using std::vector;

vector<int> sortArrayByParity(vector<int>& A)
{
    if (A.empty())
        return {};

    int i = 0;
    int j = A.size()-1;
    int k = 0;
    int n = A.size();
    vector<int> res(A.size());

    for ( ; k < n; k++)
    {
        if (A[k] % 2)
            res[j--] = A[k];
        else
            res[i++] = A[k];
    }

    return res;
}

