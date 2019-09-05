//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-04.
//
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;

vector<string> commonChars(vector<string>& A)
{
    if (A.empty())
        return {};

    int mp[102][102];
    memset(mp, 0, sizeof(mp));
    int n = A.size();
    vector<string> res;

    for (int i = 0; i < n; ++i) {
        string s = A[i];
        int len = s.length();
        for (int j = 0; j < len; j++) {
            char c = s.at(j);
            mp[i][c - 'a' + 1]++;
        }
    }


    for (int i = 1; i <= 26; ++i) {
        int minn = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            if (mp[j][i] == 0)
            {
                minn = 0;
                break;
            }
            if (mp[j][i] < minn)
                minn = mp[j][i];
        }
        for (int j = 1; j <= minn; ++j)
        {
            string tmp;
            tmp += char('a' + i - 1);
            res.push_back(tmp);
        }
    }

    return res;

}