//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-21.
//


int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int sum = (0 + n) * (n + 1) / 2;
    for (auto &i : nums)
        sum -= i;
    return sum;
}

int missingNumber1(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 1; i < n; ++i)
        sum ^= i;
    for (int i = 0; i < n; ++i)
        sum ^= nums[i];

    return sum;


}

