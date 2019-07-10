#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:

	//dp
	string longestPalindromeDP(string str)
	{
		int dp[100][100];
		memset(dp, 0, sizeof(dp));
		int beg = 0;
		dp[0][0] = 1;
		int maxLen = 0;

		for (int i = 0; i < str.length() - 1; i++)
		{
			dp[i][i] = 1;
		}

		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == str[i + 1])
			{
				dp[i][i + 1] = 1;
				beg = i;
				maxLen = 2;
			}
		}

		for (int len = 3; len <= str.length()-1; len++)
		{
			for (int i = 0; i < str.length() - 1; i++)
			{
				int j = i + len - 1;
				if (str[i] == str[j] && dp[i + 1][j - 1])
				{
					dp[i][j] = true;
					beg = i;
					maxLen = len;
				}
			}
		}

		return str.substr(beg, maxLen);
	}

	// 从中心向两边探测
	string expandAroundCenter(string s, int c1, int c2)
	{
		int l = c1, r = c2;
		int n = s.length();
		while (l >= 0 && r <= n - 1 && s[l] == s[r])
		{
			l--;
			r++;
		}

		return s.substr(l + 1, r - l - 1);
	}

	string longestPalindromeSimple(string s)
	{
		int n = s.length();
		if (n == 0)
			return "";
		string longest = s.substr(0, 1);
		for (int i = 0; i < n - 1; i++)
		{
			string p1 = expandAroundCenter(s, i, i);
			if (p1.length() > longest.length())
				longest = p1;

			string p2 = expandAroundCenter(s, i, i + 1);
			if (p2.length() > longest.length())
				longest = p2;
		}

		return longest;
	}

	string preProcess(string s)
	{
		string res = "";
		for (int i = 0; i < s.length(); ++i)
		{
			res += '#';
			res += s.substr(i, 1);
		}
		res += '#';
		return res;
	}


	string longestPalindrome(string s)
	{
		if (s.length() <= 1)
			return s;
		if (s.length() == 2)
		{
			if (s[0] == s[1])
				return s;
			else
			{
				string res = "";
				res += s[0];
				return res;
			}
		}
		int maxLen = 0;
		int R = 0;
		int M = 0;
		string str = preProcess(s);
		int n = str.length();
		int p[1000];
		memset(p, 0, sizeof(p));

		for (int i = 0; i < n - 1; i++)
		{
			int i_mirror = M - (i - M);
			int diff = R - i;
			if (diff >= 0)
			{
				if (p[i_mirror] < diff)
				{
					p[i] = p[i_mirror];
				}
				else
				{
					p[i] = diff;
					while (str[i + p[i] + 1] == str[i - p[i] - 1])
						p[i]++;
					M = i;
					R = i + p[i];
				}
			}
			else
			{
				p[i] = 0;
				while (str[i + p[i] + 1] == str[i - p[i] - 1])
					p[i]++;
				M = i;
				R = i + p[i];
			}
		}

		int mx = 0;
		int pos = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (p[i] > mx)
			{
				mx = p[i];
				pos = i;
			}
		}

		return s.substr((pos - 1 - mx) / 2, (pos - 1 - mx) / 2 + mx);
	}


};


class Solution2 {
public:
	string longestPalindrome(string s) {
		if (s.length() < 2)
			return s;

		int max_len = 1;
		int max_st = 0;
		int max_ed = 1;

		// parse repeated ones first
		int parsed_len = 0;
		string parsed_s;
		parsed_s.resize(s.length());
		vector<int> repeat_num(s.size());
		vector<int> parsed_to_s(s.size() + 1);

		for (size_t i = 0; i < s.length();)
		{
			int repeat = 1;
			while ((i + repeat) < s.length() && s[i] == s[i + repeat])
			{
				++repeat;
			}

			if (repeat > max_len)
			{
				max_len = repeat;
				max_st = i;
				max_ed = i + repeat;
			}
			parsed_to_s[parsed_len] = i;
			parsed_s[parsed_len] = s[i];
			repeat_num[parsed_len++] = repeat;

			i += repeat;
		}
		parsed_to_s[parsed_len] = s.length();

		int st = 0;
		int ed = 1;
		int center = 1;
		while (max_len / 2 < (s.length() - parsed_to_s[center]))
		{
			int rad = 1;
			int len = repeat_num[center];
			while (rad <= center && center + rad < parsed_len)
			{
				int left = center - rad;
				int right = center + rad;
				if (parsed_s[left] == parsed_s[right])
				{
					if (repeat_num[left] != repeat_num[right])
					{
						int min_rep = repeat_num[left] < repeat_num[right] ? repeat_num[left] : repeat_num[right];
						len += min_rep * 2;
						st = parsed_to_s[left + 1] - min_rep;
						ed = parsed_to_s[right] + min_rep;
						break;
					}
					else
					{
						len += repeat_num[left] * 2;
						st = parsed_to_s[left];
						ed = parsed_to_s[right + 1];
					}
				}
				else
				{
					break;
				}
				++rad;
			}

			if (len > max_len)
			{
				max_len = len;
				max_st = st;
				max_ed = ed;
			}
			++center;
		}

		return s.substr(max_st, max_len);
	}
};
int main5()
{
	string s = "ccc";
	Solution ss;
	cout << ss.longestPalindrome(s);
	return 0;
}