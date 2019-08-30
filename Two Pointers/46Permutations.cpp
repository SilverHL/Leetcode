#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> temp;
		vector<vector<int>> res;
		getIn(temp, nums, res);
		return res;
	}

	void getIn(vector<int>& temp, vector<int> &nums, vector<vector<int>> &res)
	{
		if (temp.size() == nums.size())
		{
			res.push_back(temp);
		    cout << temp[0];
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (find(temp.begin(),temp.end(), nums[i]) != nums.end())
				continue;
			temp.push_back(nums[i]);
			getIn(temp, nums, res);
			temp.pop_back();
		}
		return;
	}

};

int main46()
{
	Solution s;
	vector<int> vec = { 1, 2 ,3 };

	vector<vector<int>> res = s.permute(vec);

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}

	getchar();

	return 0;
}