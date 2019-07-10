/**************************************************
 * Leetcode 992 Subarrays With K different Integers
 * Creator: Neo
 *
 * 本题题意为 给定一个数组，求该数组的所有子数组中，所有数字数量为K 的子数组数量，
 * 使用一个hash来记录当前子数组中包含的所有数字及数量，准备一个deq，每当有数字压入deq中，
 * 就将这个数字纪录在hash中，hash中，若这个数字数量为0，就将k-1，否则直接压入。
 * 当遇到k为0时，就将结果+1， 并弹出至某个数字为该子数组中的最后一个数字为止，并且将k+1，即为本题解。
 * ************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
using namespace std;

class Solution
{

int subarraysWithKDistincts(vector<int>& A, int k)
{
    int res = 0;
    deque<int> deq;
    int mp[1000];
    memset(mp, 0, sizeof(mp));

    for (int i = 0; i < A.size(); i++)
    {
        if (k != 0)
        {
            deq.push_back(A[i]);
            if (mp[A[i]] == 0)
                k--;
            mp[A[i]]++;
        }
        else
        {
            res++;
            while (k == 0)
            {
                int n = deq[0];
                mp[n]--;
                deq.pop_front();
                if (mp[n] == 0)
                    k++;
            }
            i--;
        }
    }

    return res;
}


};
