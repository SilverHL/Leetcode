#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	
public:

	void genPar(vector<string>& res, string str, int left, int right, int max)
	{
		if (str.length() == max * 2)
		{
			res.push_back(str);
			return;
		}

		if (left < max)
		{
			genPar(res, str + "(", left + 1, right, max);
		}
		if (right < left)
		{
			genPar(res, str + ")", left, right + 1, max);
		}
	}

	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		genPar(res, "", 0, 0, n);
		
	}
};