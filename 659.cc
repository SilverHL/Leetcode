#include <vector>
#include <unordered_map>

using namespace std;

bool isPossible(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (int i : nums)
        ++mp[i];

    for (int i : nums) {
        int cnt = 0;
        if (!mp[i+cnt]) continue;
        while (mp[i+cnt] > 0) {
            --mp[i+cnt];
            cnt++;
            if (mp[i+cnt-1] >= mp[i+cnt]) 
                break;
        } 
        if (cnt < 3)
            return false;
    }

    return true;
}
