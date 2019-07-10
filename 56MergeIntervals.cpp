#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{

	static bool cmp(Interval i1, Interval i2)
	{
		if (i1.start == i2.start)
			return i1.end < i2.end;
		return i1.start < i2.start;
	}

public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		if (intervals.size() == 0)
			return vector<Interval> {};
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), cmp);

		res.push_back(move(intervals[0]));
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back().end >= intervals[i].start)
				res.back().end = max(intervals[i].end, res.back().end);
			else
				res.push_back(intervals[i]);
		}
		return res;
	}
};