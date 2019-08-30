//
// Created by 王靖煊 on 2019-07-07.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution524
{
public:
    string FindLongestWord(string s, vector<string> &d)
    {

        if (s.length() == 0)
            return "";
        string res;
        int max_len = INT_MIN;
        int s_len = s.length();
        //sort(begin(d), end(d), cmp);

        for (auto str : d)
        {
            int str_idx = 0;
            int s_idx = 0;
            int str_len = str.length();

            if (str_len < max_len)
                continue;

            while (str_idx < str_len && s_idx < s_len)
            {
                if (str[str_idx] != s[s_idx])
                {
                    s_idx++;
                } else {
                    str_idx++;
                    s_idx++;
                }
            }

            if (str_idx == str_len)
            {
                if (str_len > max_len)
                {
                    max_len = str_len;
                    res = str;
                }
            }
        }

        return res;

    }
};
