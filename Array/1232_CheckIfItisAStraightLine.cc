//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/3.
//

#include <vector>

using std::vector;

bool checkStraightLine(vector<vector<int>>& coordinates)
{
    const int n = coordinates.size();
    int k = 0;
    if (n <= 2)
        return true;

    for (int i = 3; i < n; ++i) {
        vector<int> co1 = coordinates[i-2];
        vector<int> co2 = coordinates[i-1];
        vector<int> co3 = coordinates[i];

        if ((co2[1] - co1[1]) * (co3[0] - co2[0]) != (co3[1] - co2[1]) * (co2[0] - co1[0]))
            return false;
    }

    return true;
}

bool checkStraightLine(vector<vector<int>>& coordinates)
{
    vector<double> v;
    int n=coordinates.size();
    for(int i=0;i<coordinates.size()-1;i++){
        v.push_back((double)(coordinates[i+1][1]-coordinates[i][1])/(coordinates[i+1][0]-coordinates[i][0]));
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i]!=v[i+1])return false;
    }
    return true;
}
