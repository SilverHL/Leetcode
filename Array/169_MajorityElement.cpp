//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-16.
//
/*
int majorityElement(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];

}
 */

int majorityElement(vector<int> &nums)
{
    int tmp, cnt = 0, n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (cnt == 0)
            tmp = nums[i];

        if (nums[i] == tmp)
            cnt++;
        else
            cnt--;
    }
    return tmp;
}

