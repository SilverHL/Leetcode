#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size())
		{
			if (map[s[end++]]-- > 0) 
				counter--;
			while (counter == 0)
			{
				if (end - begin < d)
					d = end - (head = begin);
				if (map[s[begin++]]++ == 0)
					counter++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};

int main76()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";

	Solution s1;
	cout << s1.minWindow(s, t);
	
	return 0;
}

class test
{
public:
	string tt(string s, string t)
	{
		int mp[128];
		for (auto i : t)
			mp[i]++;

		int counter = t.size();
		int end = 0; 
		int beg = 0;
		int d = INT_MAX, head = 0;
		for (auto i : s)
		{
			if (mp[s[end++]]-- > 0)
				counter--;

			while (counter == 0)
			{
				if (d > end - beg)
					d = end - (head = beg);
				if (mp[s[beg++]]++ == 0)
					counter++;
			}
		}
	}
};