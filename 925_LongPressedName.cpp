//
// Created by neojxwang(王靖煊) on 2019-07-12.
//
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name == "" && typed == "")
            return true;
        if (name == "" || typed == "")
            return false;

        int n_idx = 0;
        int t_idx = 0;

        int n_len = name.length();
        int t_len = typed.length();

        while (n_idx < n_len && t_idx < t_len) {
            if (name[n_idx] == typed[t_idx]) {
                n_idx++;
                t_idx++;
            } else {
                t_idx++;
            }
        }

        if (n_idx == n_len && t_idx == t_len)
            return true;
        else if (n_idx == n_len && t_idx < t_len) {
            for (int i = t_idx; i < t_len-1; i++)
                if (typed[i] != typed[i+1])
                    return false;
            return true;
        } else {
            return false;
        }
    }
};