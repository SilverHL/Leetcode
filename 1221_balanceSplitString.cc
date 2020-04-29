//
// Created by neojxwang(Íõ¾¸ìÓ) on 2020/3/10.
//

int balancedStringSplit(string s)
{
    int ln = 0;
    int rn = 0;
    int cnt = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            ln++;
        } else {
            rn++;
        }

        if (ln == rn) {
            ln = 0;
            rn = 0;
            cnt++;
        }
    }
    return cnt;
}

