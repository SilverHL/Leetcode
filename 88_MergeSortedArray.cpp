//
// Created by neojxwang(王靖煊) on 2019-08-19.
//
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int len1 = nums1.size()-1;
    int tmp = m-1;

    while (tmp >= 0)
        nums1[len1--] = nums1[tmp--];

    int index = 0;
    int i2 = 0;
    tmp = len1+1;
    len1 = nums1.size();
    while (tmp < len1  && i2 < n)
    {
        if (nums1[tmp] < nums2[i2])
            nums1[index++] = nums1[tmp++];
        else
            nums1[index++] = nums2[i2++];
    }

    while (tmp < len1)
        nums1[index++] = nums1[tmp++];

    while (i2 < n)
        nums1[index++] = nums2[i2++];
}

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    for(int i = 0; i < n; i++) {

        int j = m + i - 1;
        while(j >= 0 && nums2[i] <= nums1[j]) {
            nums1[j+1] = nums1[j];
            j--;
        }
        nums1[j+1] = nums2[i];
    }
}

