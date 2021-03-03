#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
    vector<vector<string>> res;
public:
     int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        bt(board, n, 0);
        return res.size();
    }

    void bt(vector<string> &board, int n, int level)
    {
        if (level == n) {
            res.push_back(board); 
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!isValid(board, level, i)) {
                continue;
            }
            board[level][i] = 'Q';
            bt(board, n, level+1);
            board[level][i] = '.';
        }
    }

    bool isValid(vector<string> &board, int level, int line) 
    {
        int n = board.size();
        // ???
        for (int i = level-1, j = line-1;  i >= 0 && j >= 0; --i, --j)  {
            if (board[i][j] == 'Q') 
                return false;
        }

        // ???
        for (int i = level-1, j = line+1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') 
                return false;
        }

        // ???
        for (int i = level-1; i >= 0; --i) {
            if (board[i][line] == 'Q') 
                return false;
        } 

        return true;
    }
};;
// @lc code=end

