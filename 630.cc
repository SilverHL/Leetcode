#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });

    priority_queue<int, vector<int>, std::less<int>> que;
    int res = 0;
    int end_time = 0;

    for (auto vec : courses) {
        end_time += vec[0]; 
        que.push(vec[1]);
        if (end_time > vec[1]) {
            que.pop();
        }
    }

    return que.size();
}