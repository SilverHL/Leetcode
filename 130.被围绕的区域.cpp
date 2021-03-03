#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
int dir[] = {-1, 0, 1, 0, -1};
class Solution {
    int m;
    int n;

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size();
        n = board[0].size();
    }

};

template <typename T, std::size_t N>
constexpr std::size_t (T (&)[N]) noexcept
{
    return N;
}
// @lc code=end


