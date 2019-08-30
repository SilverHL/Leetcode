//
// Created by neojxwang(王靖煊) on 2019-08-26.
//

#include <string>

using namespace std;

bool validPalindrome(string s)
{
    int n = s.length();
    if (n == 0 || n == 1)
        return true;
    int i = 0;
    int j = n-1;

    while (i < j)
    {
        if (!isalpha(s[i] && !(s[i] >= '0' && s[i] <= '9')))
        {
            i++;
            continue;
        }
        else if (!isalpha(s[j] && !(s[i] >= '0' && s[i] <= '9')))
        {
            j--;
            continue;
        }
        else
        {
            if (toupper(s[i]) != toupper(s[j]))
                return false;
        }
        i++, j--;
    }
    return true;

}


