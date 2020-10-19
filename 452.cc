#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2) {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    });

    int cnt = 1;
    int sht = points[0][1];

    for (int i = 1; i < points.size(); ++i) {
        if (sht < points[i][0]) {
            cnt++;
            sht = points[i][1];
        }
    }

    return cnt;
}