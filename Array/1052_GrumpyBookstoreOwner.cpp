//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-23.
//

#include <vector>
/*
 *
 */
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
    int l = 0;
    int r = 0;
    int sum = 0;
    int max_sum = 0;
    int i_l = 0;
    int i_r = 0;
    int n = customers.size();

    while (r < n) {
        sum += customers[r] * grumpy[r];
        r++;
        if (r - l < X)
            continue;
        else if (r - l == X) {
            if (max_sum < sum) {
                max_sum = sum;
                i_r = r;
                i_l = l;
            }
        } else {
            if (r - l != X) {
                sum -= customers[l] * grumpy[l];
                l++;
            }
            if (max_sum < sum) {
                max_sum = sum;
                i_r = r;
                i_l = l;
            }
        }
    }

    for (int i = i_l; i < i_r; ++i) {
        grumpy[i] = 0;
    }

    sum = 0;
    for (int i = 0; i < n; ++i) {
        if (!grumpy[i])
            sum += customers[i];
    }
    return sum;
}


int test(vector<int> customers, vector<int> grumpy, int X)
{
    int len = customers.size();
    int res = 0;
    for (int i = 0; i < X; i++) res += customers[i];
    for (int i = X; i < len; i++) res += (1 - grumpy[i]) * customers[i];
    int tmp = res;
    for (int st = 1; st + X -1 < len; st++)
    {
        tmp += customers[st+X-1] - customers[st-1] - (1-grumpy[st+X-1])*customers[st+X-1] + (1-grumpy[st-1])*customers[st-1];
        res = max(res, tmp);
    }
    return res;
}
