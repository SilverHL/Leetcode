#include <vector>
#include <cstdlib>
#include <limits.h>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

/*
 *  A0 A1 ... Am1-1, Am1, ... An1-1      B0 B1 ... Bm2-1, Bm2, ... Bm2-1
 *  
 * C0 C1 ... Ck-1, Ck, ... Cn1+n2-1
 *
 * k = (n1+n2+1) / 2
 * m1+m2 = k
 * Mudian must from {Am1-1, Bm2-1, Am1, Bm2}
 * And Am1 must be greater or equal than Bm2-1
 * &
 * */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();

		if (n1 > n2) {
			return findMedianSortedArrays(nums2, nums1);
		}

		int l = 0, r = n1;
		int m1 = 0, m2 = 0;
		int k = (n1 + n2 + 1) / 2;

		while (l < r) {
			m1 = l + (r - l) / 2;
			m2 = k - m1;
			
			if (nums1[m1] < nums2[m2-1]) {
				l = m1 + 1;
			} else {
				r = m1;
			}
		}

		m1 = l;
		m2 = k - l;

		int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1], 
					 m2 <= 0 ? INT_MIN : nums2[m2-1]);
		if ((n1 + n2) %2 == 1) {
			return c1;
		}
		
		int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1], 
					 m2 >= n2 ? INT_MAX : nums2[m2]);
		return (c1+c2) * 0.5;
    }
};
// @lc code=end

