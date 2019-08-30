#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> & nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
	
		for (int i = 0; i < nums.size(); i++)
		{
			int target = -nums[i];
			int front = i + 1;
			int end = nums.size() - 1;
			while (front < end)
			{
				int sum = nums[front] + nums[end];

				if (sum > target)
				{
					end--;
				}
				else if (sum < target)
				{
					front++;
				}
				else
				{
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[front]);
					tmp.push_back(nums[end]);
					res.push_back(tmp);


					while (front < end && nums[front] == tmp[1])
						front++;

					while (front < end && nums[end] == tmp[2])
						end--;
				}
			}

			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				i++;
		}

		return res;
	}
};


int main15()
{
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	string s = "0x25";
	cout << s;
	return 0;
}