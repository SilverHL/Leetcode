#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
    vector<int> res;
public:
    vector<int> pancakeSort(vector<int>& arr) {
        if (arr.empty())
            return res;
        int n = arr.size();
        sort(arr, n);
        return res;
    }

    void sort(vector<int>& arr, int end)
    {
        if (end == 1)
            return;

        int max_index = 0;
        int mx = 0;

        for (int i = 0; i < end; ++i)
        {
            if (arr[i] > mx)
            {
                mx = arr[i];
                max_index = i;
            }
        }

        if (max_index != end-1) 
        {
            reverse(arr, 0, max_index);
            res.push_back(max_index+1);
            reverse(arr, 0, end-1);
            res.push_back(end);
        }
        sort(arr, end-1);
    }

    void reverse(vector<int>& arr, int beg, int end)
    {
        while (beg < end)
        {
            int tmp = arr[beg];
            arr[beg] = arr[end];
            arr[end] = tmp;
            beg++;
            end--;
        }
    }
};
// @lc code=end

