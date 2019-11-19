#include <iostream>
#include <vector>
#include <string>

#include "Array/1014_BestSightseeingPair.cpp"
#include "Array/1040_MovingStonesUntilConsecutiveII.cpp"

using namespace std;


int main()
{
    vector<int> A = {8,7,6,5,10};
    vector<int> res = numMovesStonesII(A);
    cout << res[0] << endl;
    cout << res[1] << endl;

}

