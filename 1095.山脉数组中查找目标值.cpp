#include <iostream>
/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */
class MountainArray {
  public:
    int get(int index);
    int length();
};


// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {

    int find_peak(MountainArray &mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int find_target(MountainArray &arr, int target, int left, int right) {
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (arr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (arr.get(left) == target)
            return left;
        else 
            return -1;
    }

    int find_target_reverse(MountainArray &arr, int target, int left, int right) {
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if (arr.get(mid) < target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        if (arr.get(left) == target) 
            return left;
        else 
            return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = find_peak(mountainArr, 0, n-1);
        if (mountainArr.get(peak) == target) 
            return peak;
        int tmp = find_target(mountainArr, target, 0, peak-1);
        if (tmp == -1) 
            return find_target_reverse(mountainArr, target, peak+1, n-1);

        return tmp;
    }
};
// @lc code=end

