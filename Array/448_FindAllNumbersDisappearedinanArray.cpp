//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-16.
//

#include <vector>

using std::vector;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int miss = nums[n-1] - n;
    vector<int> res;

    for (int i = 1; i < miss; ++i) {
        int l = 0;
        int r = n;
        int mid;

        while (l < r) {
            mid = ((r - l) >> 1) + l;
            int x = nums[mid] - 1 - mid;

            if (x > i) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res.push_back(l);
    }
}
