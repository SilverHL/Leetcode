//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/11.
//

#include <vector>

using namespace std;

int triangleNumber(vector<int>& nums)
{
    const int n = nums.size();
    if (n <= 2)
        return 0;

    sort(begin(nums), end(nums));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                int vi = nums[i];
                int vj = nums[j];
                int vk = nums[k];
                if (abs(vi - vj) >= vk)
                    break;
                if (vi + vj <= vk)
                    break;
                ans++;
            }
        }
    }
    return ans;
}

int triangleNumberII(vector<int>& nums)
{
    const int n = nums.size();
    sort(begin(nums), end(nums), [](int a, int b) { return a > b; });
    int ans = 0;

    for (int c = 0; c < n; ++c) {
        int a = c + 1, b = n - 1;

        while (a < b) {
            if (nums[a] + nums[b] > nums[c]) {
                ans += (b - a);
                a++;
            } else {
                b--;
            }
        }
    }

    return ans;

}
