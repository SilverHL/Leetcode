#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    int n = intervals.size();
    vector<vector<int>> res;

    int newStart = newInterval[0];
    int newEnd = newInterval[1];

    int i = 0;
    while (i < n && intervals[i][0] < newStart)
        res.push_back(intervals[i]);

    if (!res.empty() && res.back()[1] < newStart) {
        res.push_back(newInterval);
    } else {
        res.back()[1] = max(res.back()[1], newEnd);
    }

    while (i < n) {
        vector<int> interval = intervals[i++];
        if (newEnd < interval[0])
            res.push_back(interval);
        else if (interval[0] < newStart && newStart < interval[1])
            res.back()[1] = interval[1];
    }

    return res;

}