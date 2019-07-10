#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
	int mp[4][2] = {
		{-1, 0},
		{0, -1}, 
		{1, 0},
		{0, 1}
	};

	bool res = false;
	void dfs(vector<vector<char>>& board, string word, int i, int j, int pos)
	{
		if (board[i][j] != word[pos])
			return;

		if (pos == word.length() - 1)
		{
			res = true;
			return;
		}
		
		char cur = board[i][j];
		board[i][j] = '*';
		for (int index = 0; index < 4; index++)
		{
			int tmpi = i + mp[index][0];
			int tmpj = j + mp[index][1];
			if (tmpi >= 0 && tmpi < board.size() &&
				tmpj >= 0 && tmpj < board[0].size())
			{
				cout << i << ' ' << j << endl;
				dfs(board, word, tmpi, tmpj, pos + 1);
			}
		}
		board[i][j] = cur;

	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0)
			return false;
		if (word.length() == 0)
			return true;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				dfs(board, word, i, j, 0);
		return res;
	}
};

int main79()
{
	vector<vector<char>> vec = { {'A', 'B', 'C', 'E'},
								 {'S', 'F', 'C', 'S'},
								 {'A', 'D', 'E', 'E'} };
	Solution s;
	cout <<s.exist(vec, "ABCCE");
	getchar();
	return 0;
}

class Solution1
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		m = board.size();
		n = board[0].size();
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
			{
				if (dfs(board, word.c_str(), x, y))
					return true;
			}
		return false;
	}
private:
	int m;
	int n;

	bool dfs(vector<vector<char>> &board, const char* w, int x, int y)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0' || *w != board[x][y])
			return false;
		if (*(w + 1) == '\0')
			return true;
		char t = board[x][y];
		board[x][y] = '\0';
		if (dfs(board, w + 1, x - 1, y) ||
			dfs(board, w + 1, x, y + 1) ||
			dfs(board, w + 1, x + 1, y) ||
			dfs(board, w + 1, x, y - 1))
			return true;
		board[x][y] = t;
		return false;
	}
};