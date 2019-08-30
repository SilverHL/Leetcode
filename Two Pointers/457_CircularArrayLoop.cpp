//
// Created by neojxwang(王靖煊) on 2019-08-29.
//

#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

int next(vector<int>& nums, int n)
{
    int k = nums.size();
    return (n + nums[n] + k) % k;
}

bool circularArrayLoop(vector<int>& nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int slow = i;
        int fast = next(nums, slow);
        while (nums[fast] * nums[slow] > 0 && nums[next(nums, fast)] * nums[slow] > 0)
        {
            if (slow == next(nums, slow))
                break;
            if (fast == slow)
            {
                if (slow == next(nums, slow))
                    break;
                return true;
            }
            slow = next(nums, slow);
            fast = next(nums, next(nums, fast));
        }
    }
    return false;
}

bool test(vector<int>& nums)
{
    int n = nums.size();
    vector<int> visited(n);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        unordered_set<int> mp;
        int curr = i;

        while (1)
        {
            int next = (curr + nums[curr]) % n;
            if (next < 0)
                next += n;

            if (curr == next || nums[curr] * nums[next] < 0)
                 break;
            if (mp.count(next))
                return true;
            mp.insert(curr);
            curr = next;
            visited[curr] = true;
        }
    }

    return false;
}
