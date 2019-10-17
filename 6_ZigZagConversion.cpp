//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-08.
//
#include <string>

using std::string;

string convert(string& s, int numRows)
{
    int n = s.length();
    int interval = (numRows << 1) / 2;
    string res(n, ' ');
    int cnt = 0;
    for (int i = 0; i < n; i += interval)
        res[cnt++] = s[i];

    int flag = 1;
    int i = 1;

    return "";

}

