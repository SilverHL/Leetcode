#include <vector>

using namespace std;
vector<int> largeK(vector<int>& vec, int k) {
    vector<int> t;
    int pop_max = vec.size() - k;

    for (auto i : vec) {
        while (!t.empty() && t.back() < i && pop_max) {
            t.pop_back();
            pop_max--;
        }
        t.push_back(i);
    }

    return vector<int>(t.begin(), t.begin()+k);
}

vector<int> merge(vector<int> &v1, vector<int> &v2) {
     int i = 0;
     int j = 0;

     int n1 = v1.size(); 
     int n2 = v2.size();

     vector<int> res;

     while (i < n1 && j < n2) {
         if (v1[i] < v2[j]) {
             res.push_back(v2[j++]);
         } else {
             res.push_back(v1[i++]);
         }
     }

     while (i < n1) res.push_back(v1[i++]);
     while (j < n2) res.push_back(v2[j++]);

     return res;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        if (i > nums1.size()) 
            break;
        if (k-i > nums2.size()) 
            continue;

        vector<int> v1 = largeK(nums1, i);
        vector<int> v2 = largeK(nums2, k-i);
        vector<int> tmp = merge(v1, v2);
        if (res < tmp) {
            res = tmp;
        }
    }        
    return res;
}

void prt(vector<int>& v) {
    for (auto i : v) {
        cout << i << " ";
    }

    cout << endl;
}
