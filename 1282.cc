//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/2.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes)
{
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < groupSizes.size(); ++i) {
        groups[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> res;

    for (auto iter = groups.begin(); iter != groups.end(); iter++) {
        const int& gsize = iter->first;
        const vector<int>& lst = iter->second;

        for (auto it = lst.begin(); it != lst.end(); it = next(it, gsize)) {
            vector<int> tmp{it, next(it, gsize)};
            res.push_back(tmp);
        }
    }

    return res;
}
