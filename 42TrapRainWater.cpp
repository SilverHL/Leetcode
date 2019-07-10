#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int trap(vector<int>& height)
	{
		int l = 0, r = height.size() - 1, water = 0;
		int leftMax = 0, rightMax = 0;
		while (l < r)
		{
			if (height[l] < height[r])
			{
				leftMax = max(height[l], leftMax);
				water += leftMax - height[l];
				l++;
			}
			else
			{
				rightMax = max(height[r], rightMax);
				water += rightMax - height[r];
				r--;
			}
		}

		return water;
	}
};