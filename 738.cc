#include <string>
#include <cstdlib>

using namespace std;

int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    int i;
    int n = s.length();
    int terminteIdx = 0;

    for (int i = n-1; i > 0; --i) {
        if (s[i-1] > s[i]) {
            terminteIdx = i;
            s[i-1]--;
        }
    }

    if (terminteIdx) {
        while (terminteIdx < n) { 
            s[terminteIdx++] = '9';
        }
    }

    return atoi(s.c_str());
}