//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//

#include <vector>

using std::vector;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    int max = 0;
    for (auto i : arr2)
        if (i > max)
            max = i;

    vector<int> order(max+1, -1);

    int n = arr2.size();
    for (int i = 0; i < n; i++)
        order[arr2[i]] = i;

    n = (int)order.size();
    auto cmp = [&order, &n](const int a, const int b) -> bool
    {
        bool contain_a = false, contain_b = false;
        if (a < n && order[a] != -1)
            contain_a = true;
        if (b < n && order[b] != -1)
            contain_b = true;

        if (contain_a && contain_b)
            return order[a] < order[b];
        else if (!contain_a && !contain_b)
            return a < b;
        else if (contain_a)
            return true;
        else
            return false;
    };

    sort(arr1.begin(), arr1.end(), cmp);
    return arr1;
}


vector<int> relativeSortArray1(vector<int>& arr1, vector<int>& arr2)
{
    int max = 0; //Find the maximum of arr2
    for (int a : arr2) {
        if (a > max)
            max = a;
    }
    vector<int> order(max + 1, -1);
    for (int i = 0; i < arr2.size(); ++i)
        order[arr2[i]] = i;
    auto compare = [&order](const int a, const int b) -> bool {
        bool is_a_in_arr2 = false, is_b_in_arr2 = false;
        if (a < order.size() && order[a] != -1)
            is_a_in_arr2 = true;
        if (b < order.size() && order[b] != -1)
            is_b_in_arr2 = true;
        if (is_a_in_arr2 && is_b_in_arr2) {
            return order[a] < order[b];
        } else if (!is_a_in_arr2 && !is_b_in_arr2) {
            return a < b;
        } else if (is_a_in_arr2) //so b is not in arr 2
            return true;
        else //so b is in arr2 but a is not in arr2
            return false;
    };
    sort(arr1.begin(), arr1.end(), compare);
    return arr1;
}
