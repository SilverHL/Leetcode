#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
	map<char, string> strMap = {
		{'2' , "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};

	void combine(vector<string>& res, string str, string digits, int pos)
	{
		string cur_str = strMap[digits[pos]];
		if (pos == digits.length() - 1)
		{
			for (int i = 0; i < cur_str.length(); i++)
			{
				res.push_back(str + cur_str[i]);
			}
			return;
		}

		for (int i = 0; i < cur_str.length(); i++)
		{
			combine(res, str + cur_str[i], digits, pos + 1);
		}
	}

	vector<string> letterCombinations(string digits)
	{
		vector<string> res;

		string str;
		combine(res, str, digits, 0);

		return res;
	}
};
