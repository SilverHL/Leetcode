#include <iostream>
#include <vector>
#include <string>

#include "Array/969_PancakeSorting.cpp"
#include "Array/1170_CompareStringsByFranquencyOfSmallestCharacter.cpp"
#include "Array/1089_DuplicateZeros.cpp"
#include "Array/695_MaxAreaOfIsland.cpp"


using namespace std;


int main()
{
    vector<vector<int>> vec = {{0,1,0},{1,1,1}};
    cout << maxAreaOfIsland(vec);
}

