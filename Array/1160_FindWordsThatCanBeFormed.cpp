//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//

#include <vector>
#include <string>

using namespace std;

int countCharacters(vector<string>& words, string chars)
{
    int mp[130];
    memset(mp, 0, sizeof(mp));

    for (auto c : chars)
        mp[c]++;

    int res = 0;
    for (auto word : words)
    {
        int tmp[130];
        memset(tmp, 0, sizeof(tmp));
        int n = word.length();
        int i = 0;
        for (i = 0; i < n; i++)
        {
            tmp[word[i]]++;
            if (tmp[word[i]] > mp[word[i]])
                break;
        }
        if (i == n)
            res += n;
    }
    return res;
}

