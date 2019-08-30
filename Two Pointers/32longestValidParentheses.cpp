#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		stack<int> stk;
		stk.push(-1);
		int res = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int t = stk.top();
			if (s[t] != -1 && s[t] == '(' && s[i] == ')')
			{
				stk.pop();
				res = max(res, i - stk.top());
			}
			else 
				stk.push(i);
		}
		return res;

	}
};