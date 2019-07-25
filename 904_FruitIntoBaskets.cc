#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int totalFruit(vector<int>& tree)
{
    int left = 0;
    int right = 0;
    int res = 0;
    int len = tree.size();
    int baskets = 2;
    int mp[40005];

    bzero(mp, sizeof(mp));

    while (left < len && right < len)
    {
        if (mp[tree[right++]]++ == 0)
            baskets--;
        while (baskets < 0 && left <= right)
        {
            if (--mp[tree[left++]] == 0)
                baskets++;
        }
        if (res < right - left)
            res = right - left;
    }

    return res;

}
