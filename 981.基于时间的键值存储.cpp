#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <map>

using std::string;
using std::unordered_map;
using std::map;

/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start

struct Node {
    string value;
    int timestamp;

    Node(string v, int ts) : value(v), timestamp(ts) {}
};

struct cmp
{
    bool operator()(const Node &n1, const Node &n2) 
    {
        return n1.timestamp < n2.timestamp;
    }
};


class TimeMap {
    unordered_map<string, map<int, string> > mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string> &m = mp[key];
        auto f = m.upper_bound(timestamp);

        return f == m.begin() ? "" : prev(f)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

