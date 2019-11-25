//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-25.
//
#include <vector>

using std::vector;

bool isOneBitCharacter(vector<int>& bits)
{
    int n = bits.size()-1;
    int cnt = 0;
    for (int i = n-1; i >= 0; --i)
        if (bits[i])
            cnt++;
        else
            break;

    return cnt % 2 == 0;
}

bool isOneBitC(vector<int>& bits)
{
    if (bits.size() == 1)
        return true;
    auto rit = find(next(rbegin(bits)), rend(bits), 0);
    return !(distance(next(rbegin(bits)), rit) % 2);
}

