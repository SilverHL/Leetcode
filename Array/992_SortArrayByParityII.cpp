//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//
#include <vector>

using std::vector;
using std::swap;

vector<int> sortArrayByParityII(vector<int>& A)
{
    if (A.empty())
        return {};

    int n = A.size();
    int j = 0;
    int k = 0;

    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            while (j < n && A[j] % 2 == 1)
                j++;
            res[i] = A[j++];
        }
        else
        {
            while (k < n && A[k] % 2 == 0)
                k++;
            res[i] = A[k++];
        }
    }
    return res;
}

vector<int>& sortArray(vector<int>& A)
{
    int n = A.size(), i = 0, j = 1;
    while (i < n && j < n){
        while (i < n && A[i] % 2 == 0) i += 2;
        while (j < n && A[j] % 2) j += 2;
        if (i >= n || j >= n) break;
        swap(A[i], A[j]);
        //cout << A[i] << ' ' << A[j] << endl;
        i += 2, j += 2;
    }
    return A;
}
