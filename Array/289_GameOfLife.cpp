//
// Created by neojxwang(������) on 2019-11-21.
//

#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board)
{
    int m = board.size();
    int n = m ? board[0].size() : 0;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            int lives = 0;

            for (int x = max(0, i-1); x < min(m, i+2); ++x)
                for (int y = max(0, j-1); y < min(n, j+2); ++y)
                    lives += board[x][y] & 1;

            if (lives == 3 || (lives - board[i][j]) == 3)
                board[i][j] |= 0b10;
        }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] >>= 1;
}

