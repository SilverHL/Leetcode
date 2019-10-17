#include <iostream>
#include <vector>
#include <string>

#include "Array/969_PancakeSorting.cpp"
#include "Array/1170_CompareStringsByFranquencyOfSmallestCharacter.cpp"
#include "Array/1089_DuplicateZeros.cpp"
#include "Array/695_MaxAreaOfIsland.cpp"
#include "Array/1011_CapacityToShipPackagesWithinDDays.cpp"
#include "Array/169_MajorityElement.cpp"
#include "Array/448_FindAllNumbersDisappearedinanArray.cpp"

#include "6_ZigZagConversion.cpp"

using namespace std;


int main()
{
    vector<int> vec = {4,3,2,7,8,2,3,1};
    vector<int> res = findDisappearedNumbers(vec);

    for_each(begin(res), end(res), [](int n) { cout << n << endl;});
}

