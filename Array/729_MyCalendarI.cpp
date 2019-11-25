//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-21.

#include <map>
#include <vector>

using namespace std;

class MyCalendar1 {
private:
    vector<int> mp_;
public:
    MyCalendar1() {

    }

    bool book(int start, int end) {
        int n = mp_.size();
        for (int i = 0; i < n; i += 2)
            if (max(mp_[i], start) < min(mp_[i+1], end))
                return false;
        mp_.push_back(start);
        mp_.push_back(end);
        return true;
    }
};

class MyCalendar
{
private:
    map<int, int> mp;
public:

    MyCalendar(){}
    bool book(int start, int end)
    {
        map<int, int>::const_iterator it = mp.lower_bound(start);
        if (it != mp.cend() && it->first < end)
            return false;
        if (it != mp.cend() && (--it)->second > start)
            return false;
        mp[start] = end;
        return true;
    }
};
