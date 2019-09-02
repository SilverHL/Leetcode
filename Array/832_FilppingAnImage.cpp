//
// Created by neojxwang(王靖煊) on 2019-08-30.
//

#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int>> filpAndRevertImage(vector<vector<int>> &A)
{
    if (A.empty())
        return {};
    for (auto &arr : A)
    {
        int i = 0;
        int j = arr.size()-1;

        while (i < j)
        {
            std::swap(arr[i], arr[j]);

            arr[i] = !arr[i];
            arr[j] = !arr[j];
            i++;
            j--;
        }

        if (i == j)
            arr[i] = !arr[i];
    }

    return A;
}