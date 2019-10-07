//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-25.
//

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int max_len = 0;
    int tmp = 1;

    for (int i = 0; i < n-1; ++i) {
        while (i < n-1 && nums[i] == nums[i+1])
            tmp++;
        if (tmp > max_len)
            max_len = tmp;
        tmp = 1;
    }
    return max_len;
}

int findMaxConsecutive(vector<int>& nums)
{
}ws
