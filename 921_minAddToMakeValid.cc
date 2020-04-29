//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/12.
//

#include <vector>
#include <string>

using namespace std;

int minAddToMakeValid(string S)
{
    int l = 0;
    int r = 0;

    for (auto c : S) {
        if (c == '(') {
            l++;
        } else {
            r++;
        }

        if (c == ')') {
            if (l > 0)
                l--, r--;
        }
    }

    return l + r;
}

