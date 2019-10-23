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
#include "Array/216_CombinationSumIII.cpp"

#include "6_ZigZagConversion.cpp"

using namespace std;


int main()
{
    vector<vector<int>> res = combinationSum3(3, 7);
    for (auto i : res) {
        for (auto j : i)
            cout << j << " ";
        cout <<  endl;
    }


}

