#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
	void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> candi, int remain, int start)
	{
		if (remain < 0)
			return;
		else if (remain == 0)
			res.push_back(temp);
		else
		{
			for (int i = start; i < candi.size(); i++)
			{
				temp.push_back(candi[i]);
				backtrack(res, temp, candi, remain - candi[i], i);
				temp.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int> > res;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		backtrack(res, temp, candidates, target, 0);
	}
};

int main39()
{
	int test[] = { 1, 99 };
	int *p = test;
	int a;
	cout << *p << endl; 
	cout << *p++ << endl;;
	cout << *p;
	cin >> a;
	return 0;
}