#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maximalRectangle1(vector<vector<char>> &matrix)
	{
		int mx = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			vector<int> tmp;
			for (int j = 0; j < matrix[0].size(); j++)
			{
				int counter = 0;
				int count = i;
				while (count >= 0 && matrix[count][j] == '1')
				{
					counter++;
					count--;
				}
				tmp.push_back(counter);
			}
			mx = max(mx, getMax(tmp));
		}

		return mx;
	}

	int getMax(vector<int> input)
	{
		int res = 0;
		vector<int> index;
		input.push_back(0);

		for (int i = 0; i < input.size(); i++)
		{
			while (index.size() > 0 && input[index.back()] >= input[i])
			{
				int h = input[index.back()];
				index.pop_back();

				int sidx = input.size() ? input.back() : -1;
				res = max(res, h * (i - sidx - 1));
			}
			index.push_back(i);
		}
		return res;
	}

	int maximalRectangle(vector<vector<char>> &matrix)
	{
		if (matrix.size() == 0)
			return 0;

		const int m = matrix.size();
		const int n = matrix[0].size();

		vector<int> left(n, 0);
		vector<int> right(n, n);
		vector<int> height(n, 0);

		int res = 0;

		for (int i = 0; i < m; i++)
		{
			int curLeft = 0;
			int curRight = 5;
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
					left[j] = max(left[j], curLeft);
				else
				{
					curLeft = j + 1;
					left[j] = 0;
				}
			}

			for (int j = n-1; j >= 0; j--)
			{
				if (matrix[i][j] == '1')
					right[j] = min(right[j], curRight);
				else
				{
					curRight = j - 1;
					right[j] = n;
				}
			}

			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
					right[j]++;
				else
					right[j] = 0;
			}

			for (int j = 0; j < n; j++)
			{
				res = max(res, (right[j] - left[j]) * height[j]);
			}
		}

		return res;


	}
};