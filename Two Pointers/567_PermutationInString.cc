//
// Created by neojxwang(王靖煊) on 2019-08-09.
//

#include <vector>
#include <string>

using namespace std;

bool checkInclusion(const string &s1, const string &s2)
{
    const int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;
    vector<int> mp(27, 0);
    int i = 0, j = n1;

    for (const auto &c : s1)
        --mp[c-'a'];

    for (int i = 0; i < j; i++)
        ++mp[s2[i]-'a'];

    while (j < n2)
    {
        if (equal(mp.begin(), mp.end(), mp.rbegin()))
            return true;

        ++mp[s2[j++] - 'a'];
        --mp[s2[i++] - 'a'];
    }

    return equal(mp.begin(), mp.end(), mp.rbegin());
}
