#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{

	void damn(vector<int> &nums, int pos, vector<vector<int>>& res, vector<int> &tmp)
	{

		res.push_back(tmp);

		for (int i = pos; i < nums.size(); i++)
		{
			tmp.push_back(nums[i]);
			damn(nums, i+1, res, tmp);
			tmp.pop_back(); 
		}
	}
public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> tmp;
//		res.push_back(vector<int>{});
		damn(nums, 0, res, tmp);
		return res;
	}
};


int main78()
{
	vector<int> vec = { 1, 2 ,3 };
	Solution s;
	vector<vector<int>> res = s.subsets(vec);
	for (auto i : res)
	{
		for (auto j : i)
			cout << j << ' ';
		cout << endl;
	}
	getchar();

	return 0;
}