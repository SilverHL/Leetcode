//
// Created by neojxwang(王靖煊) on 2019-07-22.
//

#include <vector>
#include <iostream>

using namespace std;

int numRescueBoats(vector<int>& people, int limit)
{
    sort(begin(people), end(people));

    int beg = 0;
    int end = people.size()-1;
    int count = 0;


    while (beg <= end)
    {
        if (people[beg] + people[end] > limit)
        {
            end--;
            count++;
        }
        else
        {
            beg++;
            end--;
            count++;
        }
    }

    return count;
}

