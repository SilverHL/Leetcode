#include <vector>
#include <string>

using namespace std;

const int maxn = 105;
int dp[maxn][maxn];  //最大数
int sum[maxn][maxn]; //方案数
const int mod = 1e9 + 7;
//const int t='S'+'E'-2*'0';
class Solution
{
public:
    void updata(int i, int j, vector<string> &board)
    {
        if (board[i][j] == 'X')
            dp[i][j] = -1;
        else
        {

            int mx = max(dp[i + 1][j], max(dp[i][j + 1], dp[i + 1][j + 1]));
            dp[i][j] = mx >= 0 ? mx + board[i][j] - '0' : -1;
            if (dp[i][j] != -1)
            {
                if (dp[i][j] == dp[i + 1][j] + board[i][j] - '0')
                    sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
                if (dp[i][j] == dp[i][j + 1] + board[i][j] - '0')
                    sum[i][j] = (sum[i][j] + sum[i][j + 1]) % mod;
                if (dp[i][j] == dp[i + 1][j + 1] + board[i][j] - '0')
                    sum[i][j] = (sum[i][j] + sum[i + 1][j + 1]) % mod;
            }
        }
        //    cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        int l1 = board.size();
        int l2 = board[0].size();
        board[0][0] = '0';
        board[l1 - 1][l2 - 1] = '0';
        for (int i = l1 - 1; i >= 0; i--)
        {
            if (board[i][l2 - 1] == 'X' || dp[i + 1][l2 - 1] == -1)
                dp[i][l2 - 1] = -1;
            else
            {
                dp[i][l2 - 1] = dp[i + 1][l2 - 1] + board[i][l2 - 1] - '0';
                sum[i][l2 - 1] = 1;
            }
        }
        for (int i = l2 - 1; i >= 0; i--)
        {
            if (board[l1 - 1][i] == 'X' || dp[l1 - 1][i + 1] == -1)
                dp[l1 - 1][i] = -1;
            else
            {
                dp[l1 - 1][i] = dp[l1 - 1][i + 1] + board[l1 - 1][i] - '0';
                sum[l1 - 1][i] = 1;
            }
        }
        for (int i = l1 - 2; i >= 0; i--)
            for (int j = l2 - 2; j >= 0; j--)
            {
                updata(i, j, board);
            }
        //  for(int i=0;i<l1;i++){
        //  for(int j=0;j<l2;j++)
        //  {
        //      cout<<dp[i][j]<<"   ";
        //  }
        //  cout<<endl;
        //  }
        vector<int> ans;
        ans.push_back(dp[0][0] > 0 ? dp[0][0] : 0);
        ans.push_back(sum[0][0]);
        return ans;
    }
};