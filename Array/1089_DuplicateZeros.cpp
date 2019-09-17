//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-10.
//

#include <vector>

using std::vector;
void duplicateZeros(vector<int>& arr)
{
    int n = arr.size();
    int old_idx = 0;
    int new_idx = 0;

    while (old_idx < n) {
        old_idx++;
        if (arr[new_idx++] == 0)
            old_idx++;
    }

    old_idx--;
    new_idx--;

    if (old_idx == n) {
        arr.back() = 0;
        old_idx -= 2;
        new_idx--;
    }

    while (old_idx >= 0) {
        arr[old_idx--] = arr[new_idx];
        if (arr[new_idx--] == 0)
            arr[old_idx--] = 0;
    }

}

