#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	int largestRectangleArea1(vector<int>& height)
	{
		int ret = 0;
		height.push_back(0);
		vector<int> index;

		for (int i = 0; i < height.size(); i++)
		{
			while (index.size() > 0 && height[index.back()] >= height[i])
			{
				int h = height[index.back()];
				index.pop_back();

				int sidx = index.size() > 0 ? index.back() : -1;
				if (h * (i - sidx - 1) > ret)
					ret = h * (i - sidx - 1);
			}
			index.push_back(i);
		}

		return ret;
	}

	vector<int> nextExceed(vector<int> &input)
	{
		vector<int> result(input.size(), -1);
		stack<int> monoStack;
		for (int i = 0; i < input.size(); i++)
		{
			while (monoStack.size() && input[monoStack.top()] < input[i])
			{
				result[monoStack.top()] = i - monoStack.top();
				monoStack.pop();
			}
			monoStack.push(i);
		}

		return result;
	}

	int largestRectangleArea(vector<int> &height)
	{
		int ret = 0;
		height.push_back(0);
		vector<int> index;

		for (int i = 0; i < height.size(); i++)
		{
			while (index.size() > 0 && height[index.back()] >= height[i])
			{
				int h = height[index.back()];
				index.pop_back();

				int sidx = index.empty() ? -1 : index.back();
				ret = max(ret, h * (i - sidx - 1));
			}
			index.push_back(i);
		}
		return ret;
	}
};


int main()
{
	vector<int> vec = { 3, 1, 3, 2, 2 };
	Solution s;
	cout <<  s.largestRectangleArea(vec);
	getchar();
	return 0;
}