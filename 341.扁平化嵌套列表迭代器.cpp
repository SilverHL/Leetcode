#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
 
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    deque<int> deq;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto node : nestedList) 
            traverse(node); 
    }
    
    int next() {
        int tmp = deq.front();
        deq.pop_front();
        return tmp;
    }
    
    bool hasNext() {
        return !deq.empty();
    }

    void traverse(NestedInteger &node)
    {
        if (node.isInteger()) {
            deq.push_back(node.getInteger());
        } else {
            for (auto node : node.getList()) 
                traverse(node);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

