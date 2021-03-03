#include <stack>
#include <map>

using namespace std;


/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
    stack<pair<int, int>> stocks;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if (stocks.empty()) {
            stocks.push({price, 1});
            return 1;
        }

        int ret = 1;
        while (!stocks.empty() && stocks.top().first <= price) {
            ret += stocks.top().second;
            stocks.pop();
        }

        stocks.push({price, ret});
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

