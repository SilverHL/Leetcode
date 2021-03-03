#include <vector>
#include <iostream>

using namespace std;


int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1; 
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        }
        cout << mid << endl;
        if (nums[mid] >= nums[left]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}