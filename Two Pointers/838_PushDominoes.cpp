//
// Created by neojxwang(王靖煊) on 2019-07-18.
//

#include <string>

using namespace std;

string PushDominoes(string dominoes)
{
    int beg = 0, end = 0;
    string res;
    int len = dominoes.length();
    char last = ' ';

    while (beg < len)
    {
        end = beg;
        while (end + 1 < len && dominoes[end] == '.')
            end++;

        if (dominoes[end] == 'L') {
            if (last == 'R')
                res += string((end - beg) / 2+1, 'R') + string((end - beg) % 2 , '.') + string((end - beg) / 2 +1, 'L');
            else
                res += string((end - beg + 1) , 'L');

            last = 'L';
        } else if (dominoes[end] == 'R') {
            if (last == 'R')
                res += string((end - beg + 1) , 'R');
            else
                res += string((end - beg) , '.');

            last = 'R';
        }
        beg = end + 1;
    }

    if (last == 'R')
        res += string((len - res.length()), 'R');
    else
        res += string((len - res.length()), '.');

    return res;


}

