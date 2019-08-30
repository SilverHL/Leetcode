//
// Created by neojxwang(王靖煊) on 2019-07-22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height)
{
    int left = 0;
    int right = height.size()-1;
    int leftMax = 0;
    int rightMax = 0;
    int res = 0;

    while (left < right)
    {
        leftMax = max(height[left], leftMax);
        rightMax = max(height[right], rightMax);

        if (leftMax > rightMax) {
            res += rightMax - height[right];
            right--;
        } else {
            res += leftMax - height[left];
            left++;
        }
    }

    return res;
}

int trap1(vector<int>& height)
{
    stack<int> stk;
    int res = 0;
    int i = 0;
    int sz = height.size();

    while (i < sz)
    {
        if (stk.empty() || height[stk.top()] >= height[i])
            stk.push(i++);
        else {
            int cur  = height[stk.top()];
            stk.pop();
            int len = i - stk.top() - 1;
            int h = min(stk.top(), height[i]);
            res += (h - cur) * len;
        }
    }

    return res;
}
