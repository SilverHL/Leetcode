//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-06.
//

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int f(string &word){
    sort(word.begin(), word.end());
    int count = 1;
    int i = 1;
    while(i<word.length()&&word[i] == word[0]){
        count++;
        i++;
    }
    return count;
}
vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> res;
    vector<int> nums1(queries.size());
    vector<int> nums2(words.size());
    for(string &str1:queries){
        nums1.push_back(f(str1));
    }
    for(string &str2:words){
        nums2.push_back(f(str2));
    }
    for(int i :nums1){
        int count = 0;
        for(int j:nums2){
            if(i<j){
                count++;
            }
        }
        res.push_back(count);
    }
    return res;
}


