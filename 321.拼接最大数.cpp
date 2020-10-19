#include <stack>
#include <vector>
#include <climits>

using namespace std;

/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;

        for (int i = 0; i <= k; ++i) {
            if (i > nums1.size()) 
                break;
            if (k-i > nums2.size()) 
                continue;
            
            vector<int> v1 = largeK(nums1, i);
            vector<int> v2 = largeK(nums2, k-i);
            vector<int> tmp = merge(v1, v2);

            if (res < tmp){                    
                res = tmp;
            }
        }

        return res;
    }

    vector<int> largeK(vector<int> &v, int k)
    {
        vector<int> res;
        int pop_remain = v.size() - k;

        for (auto i : v) {                
            while (pop_remain && !res.empty() && res.back() < i) {
                pop_remain--;
                res.pop_back();
            }
            res.push_back(i);
        }

        return vector<int>(res.begin(), res.begin() + k);
    }

    vector<int> merge(vector<int>& v1, vector<int>& v2) 
    {
        vector<int> res;
        while (!v1.empty() && !v2.empty()) {                
            if (v1 > v2) {
                res.push_back(v1[0]);
                v1.erase(v1.begin());
            } else {
                res.push_back(v2[0]);
                v2.erase(v2.begin());
            }
        }

        int i = 0;
        int j = 0;

        int n1 = v1.size();
        int n2 = v2.size();

        while (i < n1) { res.push_back(v1[i++]); }
        while (j < n2) { res.push_back(v2[j++]); }

        return res;
    }

};
// @lc code=end

