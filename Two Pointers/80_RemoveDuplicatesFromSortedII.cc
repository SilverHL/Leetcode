//
// Created by neojxwang(王靖煊) on 2019-07-25.
//

#include <vector>
#include <string>

using namespace std;


int removeDups(vector<int>& nums)
{

    int i = 0;

    for (auto e : nums)
        if (e < 2 || e > nums[i-2])
            nums[i++] = e;

    return i;
}