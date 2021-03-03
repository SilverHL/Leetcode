#include <vector>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

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
    unordered_map<string, set<Node, cmp>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        if (mp.count(key) == 0) {
            std::set<Node, cmp> s;
            mp[key] = s;
        }
        mp[key].insert(Node(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key) == 0 || mp[key].empty()) 
            return "";
        
        auto s = mp[key];
        auto fnd = s.lower_bound(Node("", timestamp));

        if (fnd == s.end()) {
            return s.rbegin()->value;
        }
        if (fnd == s.begin()) {
            if (fnd->timestamp == timestamp) {
                return fnd->value;
            } else {
                return "";
            }
        }

        auto res = --fnd;
        return res->value;
    }
};
