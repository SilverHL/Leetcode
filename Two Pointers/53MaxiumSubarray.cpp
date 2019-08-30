#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)

	{
		vector<int> deq;
		int sum = 0;
		int max = INT_MIN;
		for (auto i : nums)
		{
			sum += i;
			if (sum > max)
				max = sum;
			if (sum < 0)
			{
				sum = 0;
			}
		}

		return max;
	}
};


int main53()
{
	Solution s;
	vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };

	cout << s.maxSubArray(vec);

	return 0;
}

