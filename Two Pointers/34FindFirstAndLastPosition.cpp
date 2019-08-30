#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	int findLowerBound(vector<int>& nums, int target)
	{
		int beg = 0; 
		int end = nums.size();
		int mid = (beg + (end - beg) >> 1);
		while (beg < end)
		{
			if (nums[mid] < target)
				beg = mid + 1;
			else
				end = mid;

			mid = (beg + (end - beg) >> 1);
		}

		return beg;
	}

public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> res;
		int idx1 = findLowerBound(nums, target);
		int idx2 = findLowerBound(nums, target + 1) - 1;
		
		if (idx1 < nums.size() && nums[idx1] == target)
			return { idx1, idx2 };
		else
			return { -1, -1 };
	}
};

int main34()
{
	Solution s;
	vector<int> test = { 1, 2, 3, 3, 3, 5, 6 };
	vector<int> res = s.searchRange(test, 3);
	cout << res[0] << " " << res[1];
	return 0;
}