#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int len1 = word1.length();
		int len2 = word2.length();

		int dp[1000][1000];

		for (int i = 0; i < len1+1; i++)
			dp[i][0] = i;
		for (int i = 0; i < len2+1; i++)
			dp[0][i] = i;

		for (int i = 1; i < len1+1; i++)
			for (int j = 1; j < len2+1; j++)
			{
				if (word1[i - 1] = word2[j - 1])
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		return dp[len1][len2];
	}
};