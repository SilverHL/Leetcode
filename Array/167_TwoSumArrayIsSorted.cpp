//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-07.
//

#include <vector>

using std::vector;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;
    vector<int> res;

    while (i < j) {
        int tmp = numbers[i] + numbers[j];
        if (tmp < target)
            i++;
        else if (tmp > target)
            j--;
        else {
            res.push_back(i);
            res.push_back(j);
            return res;
        }
    }

    return {};
}
