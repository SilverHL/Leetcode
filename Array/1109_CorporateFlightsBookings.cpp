//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-19.
//

#include <vector>

using std::vector;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
{
    vector<int> res(n, 0);
    int len = bookings.size();
    for (int i = 0; i < len; ++i)
    {
        int beg = bookings[i][0];
        int end = bookings[i][1];
        int seats = bookings[i][2];

        res[beg-1] += seats;
        if (end < n)
            res[end] -= seats;
    }

    for (int i = 1; i < n; ++i)
        res[i] += res[i-1];
    return res;
}

