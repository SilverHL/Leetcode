//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-29.
//

#include <vector>
#include <opencl-c.h>

using std::vector;
using std::max;

int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    if (duration == 0)
        return 0;
    int n = timeSeries.size();
    int m = 0;

    for (int i = 0; i < n-1; ++i) {
        m += min(timeSeries[i+1] - timeSeries[i], duration);
    }
    m += duration;
    return m;
}

int findPoisonedDuration2(vector<int>& a, int d)
{
    int len = a.size(), res = 0;
    if (!len) return 0;
    for (int i = 0; i < len - 1; i++) {
        res += min(a[i + 1] - a[i], d);
    }
    return res + d;
}
