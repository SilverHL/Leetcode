//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-19.
//

#include <vector>

using std::vector;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination)
{
    if(start == destination)
        return 0;
    int total = accumulate(distance.begin(), distance.end(), 0);
    if(start > destination)
        swap(start, destination);
    int clockwise = accumulate(distance.begin() + start, distance.begin() + destination, 0);
    int anticlockwise = total - clockwise;
    if(clockwise < anticlockwise)
        return clockwise;
    return anticlockwise;

}


