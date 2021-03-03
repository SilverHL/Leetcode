#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    int mp[128];
    memset(mp, 0, sizeof(mp));

    for (auto i : p) 
        mp[i]++;
    
    int cnt = p.length();

    int j = 0;
    int n = s.length();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]] == 0) {
            while(j != i) {
                mp[s[j++]]++;
                cnt++;
            } 
            continue;
        } else {
            mp[s[i]]--; 
            cnt--;
        }

        if (cnt == 0) {
            res.push_back(j);
            mp[s[j++]]++;
            cnt++;
        }
    }

    return res;
}