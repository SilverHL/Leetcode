#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n-1;

    if (nums[left] < nums[right]) return nums[left];

    while (left < right) {
        int mid = left + ((right - left) >> 1);

        if (nums[right] == nums[mid]) {
            --right;
            continue;
        }

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }    

    return nums[right];
}