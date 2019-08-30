//
// Created by neojxwang(王靖煊) on 2019-08-25.
//

#include <vector>
#include <string>

using std::vector;
using std::string;

int strStr(string haystack, string needle)
{
    int hlen = haystack.length();
    int nlen = needle.length();

    if (!nlen)
        return 0;
    if (!hlen || hlen < nlen)
        return -1;

    int j = 0;
    for (int i = 0; i < hlen; i++)
    {
        if (haystack[i] == needle[j])
        {
              
        }
    }

}

