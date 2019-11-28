//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/11/28.
//
#include <vector>
#include <string>

using std::vector;
vector<vector<int>> largeGroupPositions(std::string S)
{
    int n = S.length();
    vector<vector<int>> res;
    int i = 0;
    int j = 0;

    while (j < n-1) {
        if (S[j] == S[j+1]) {
            j++;
            continue;
        }

        if (j - i + 1 >= 3) {
            res.push_back(vector<int>{i, j});
        }

        j += 1;
        i = j;
    }

    if (j - i + 1 >= 3)
        res.push_back(vector<int>{i, j});

    return res;
}

vector<vector<int>> largeGroupPosition(std::string S)
{
    int n = S.length();
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (j < n) {
        while (j < n && S[j] == S[i])
            j++;
        if (j - i >= 3)
            res.push_back(vector<int>{i, j-1});
        i = j;
    }
    return res;
}
