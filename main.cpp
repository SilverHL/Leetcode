#include <iostream>
#include <vector>
#include <string>

#include "Array/1014_BestSightseeingPair.cpp"
#include "Array/1040_MovingStonesUntilConsecutiveII.cpp"
#include "Array/1109_CorporateFlightsBookings.cpp"

using namespace std;


int main()
{
    vector<vector<int>> A = {
            {1,2,10},{2,3,20},{2,5,25}};
    vector<int> res = corpFlightBookings(A, 5);
    for_each(begin(res), end(res), [](int n) { cout << n << endl; });

}

