#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if (pushed.empty())
        return true;

    stack<int> stk; 
    int j = 0;
    int i = 0;
    int n = pushed.size();

    while (i < n) {

        if (pushed[i] == popped[j]) {
            ++i,++j;
            continue;
        }

        if (stk.empty() || (stk.top() != popped[j])) {
            stk.push(pushed[i]);
            i++;
            continue;
        } else if (stk.top() == popped[j]) {
            stk.pop();
            j++;
        }
    }

    while (j < n) {
        if (stk.top() == popped[j++]) 
            stk.pop();
        else 
            break;
    }

    return stk.empty();
}