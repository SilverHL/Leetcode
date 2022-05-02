#include <vector>
#include <iostream>
#include <math.h>
#include <stack>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution1 {
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> l;
        for (auto& i: cards) {
            l.emplace_back(i);
        }
        return solve(l, 0, 0);
    }

    bool solve(vector<double> &l, int in, int jn) {
        if (l.size() == 0) {
            return false;
        }
        if (l.size() == 1) {
            if (fabs(l[0] - TARGET) < EPSILON) {
                return true;
            }
            return false;
        }

        int sz = l.size();
        for (int i = in+1; i < sz; i++) {
            for (int j = jn+1; j < sz; j++) {
                if (i == j) continue;
                vector<double> list2;
                for (int k = 0; k < sz; k++) {
                    if (k == i || k == j) 
                        continue;
                    list2.emplace_back(l[k]);
                }

                for (int k = 0; k < 4; k++) {
                    if (k < 2 && i > j) {
                        continue;
                    }
                    
                    if (k == ADD) {                            
                        list2.emplace_back(l[i] + l[j]);
                    } else if (k == MULTIPLY) {
                        list2.emplace_back(l[i] * l[j]);
                    } else if (k == SUBTRACT) {
                        list2.emplace_back(l[i] - l[j]);
                    } else {
                        if (fabs(l[j]) < EPSILON) {
                            continue;
                        }
                        list2.emplace_back(l[i] / l[j]);
                    }

                    if (solve(list2,i , j)) {
                        return true;
                    }
                    list2.pop_back();
                }
            }
        }
        return false;
    }

};

class Solution{
public:
    // 计算逆波兰表达式
    float calRPN(const string& exp) {
        cout << exp << endl;
        stack<float> opnd;
        for (int i = 0; i < exp.length(); ++i) {
            if (isdigit(exp[i])) 
                opnd.push(exp[i] - '0');
            else {
                float n2 = opnd.top();
                opnd.pop();
                float n1 = opnd.top();
                opnd.pop();

                // 除以0的情况应当直接咔嚓
                if (!n2 && exp[i] == '/') return -1;

                switch(exp[i]) {
                    case '+':
                        opnd.push(n1 + n2);
                        break;
                    case '-':
                        opnd.push(n1 - n2);
                        break;
                    case '*':
                        opnd.push(n1 * n2);
                        break;
                    case '/':
                        opnd.push(n1 / n2);
                        break;
                }
            }
        }
        
        return opnd.top();
    }

    bool judgePoint24(vector<int>& nums) {
        // 转用字符串表示方便逆波兰计算
        string src, res;
        // 数字和加减乘除都一股脑往里加
        for (int i = 0; i < 4; ++i)
            src += nums[i] + '0';
        src.append("+-*/");

        vector<bool> vis(7);
        return permutation(src, vis, res, 0, 0);
    }


    bool permutation(const string& src, vector<bool>& vis, string& res, 
        const int& ncnt, const int& opcnt) {
        // ncnt为数字个数，opcnt为运算符个数
        // 通过以下三个条件，忽略明显不符合逆波兰计算的排列
        if ((opcnt && ncnt && opcnt >= ncnt) || opcnt > 3 || ncnt > 4)
            return false;
        
        if (res.size() == 7) 
            return abs(calRPN(res) - 24) < 0.01;
            // 浮点数判断相等（被3388的样例坑了）
            // 此题用0.1作误差也没问题，但正常情况最好10^-6

        // 用哈希是为了去除有重复元素的重复排列（如3388）
        unordered_set<char> numset;
        for (int i = 0; i < 8; ++i) {
            if (!vis[i] && numset.find(src[i]) == numset.end()) {
                res.push_back(src[i]);

                if (isdigit(src[i])) {
                    numset.insert(src[i]);
                    vis[i] = true;
                    // 值相同且位置相同的数字不应再出现，所以要vis标记
                    // 而操作符可以重复出现，所以不标记

                    if (permutation(src, vis, res, ncnt + 1, opcnt))
                        return true;
                }
                else {
                    if (permutation(src, vis, res, ncnt, opcnt + 1))
                        return true;
                }
                
                res.pop_back();
                vis[i] = false;
            }
        }
        return false;
    }
};

// @lc code=end

int main()
{
    cout << "test" << endl;
}