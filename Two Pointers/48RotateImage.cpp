#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		vector<vector<int>> res;

		if (matrix.size() == 0)
			return;

		for (int j = 0; j < matrix.size(); j++)
		{
			vector<int> temp;
			for (int i = matrix.size()-1; i >= 0; --i)
				temp.push_back(matrix[i][j]);
			res.push_back(temp);
		}

		matrix = res;
	}
};

int main48()
{
	vector<vector<int>> test = {
		{5, 1, 9, 11},
			{2, 4, 8, 10},
			{13, 3, 6, 7},
			{15, 14, 12, 16}
	};

	Solution s;
	s.rotate(test);

	cout << test[0][0];
	return 0;
}
