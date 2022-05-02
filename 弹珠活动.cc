#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool collapse(int i, int j)
{
    if (i > 0 && j < 0) return true;
    return false;
}

vector<int> findRest(vector<int>& vec)
{
    stack<int> stk;
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (stk.empty()) {
            stk.push(vec[i]);
            continue;
        }


        if (collapse(stk.top(), vec[i])) {
            if (stk.top() == vec[i]) {
                stk.pop();
                continue;
            }

             

        }
    }
}
