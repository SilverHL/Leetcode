#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groudAnagrams(vector<string> &strs)
	{
		map<string, vector<string>> mp;
		for (auto s : strs)
		{
			string t = s;
			sort(t.begin(), t.end());
			mp[t].push_back(s);
		}

		vector<vector<string>> res;

		for (auto item : mp)
		{
			res.push_back(item.second);
		}

		return res;
	}
};