//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-04.
//
#include <vector>
#include <string>

using std::vector;

bool isOk(int i, int j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}
int numRookCaptures(vector<vector<char>>& board)
{
    int r, l;

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if ( board[i][j] == 'R')
                r = i, l = j;

    int mp[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int res = 0;

    for (int i = 0; i < 4; i++)
    {
        int tmp_r = r + mp[i][0];
        int tmp_l = l + mp[i][1];
        while (isOk(tmp_r, tmp_l) && board[tmp_r][tmp_l] == '.')
        {
             tmp_r += mp[i][0];
             tmp_l += mp[i][1];
        }

        if (isOk(tmp_r, tmp_l) && board[tmp_r][tmp_l] == 'p')
            res++;
    }

    return res;

}

