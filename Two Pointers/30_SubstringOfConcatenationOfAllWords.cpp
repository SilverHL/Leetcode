//
// Created by neojxwang(王靖煊) on 2019-08-29.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using std::vector;
using std::string;
using std::unordered_map;
using std::map;

vector<int> findSubstring(string s, vector<string>& words)
{
    unordered_map<string,int> hash;
    vector<int> res;
    int n = s.length(),m = words.size();
    if(n == 0 || m == 0) return res;
    int len = words[0].length(),end = n - m * len;
    if(n < m * len) return res;
    for(auto word:words)
        hash[word] ++;
    for(int i = 0 ;i <= end;i ++)
    {
        unordered_map<string,int> cur_hash;
        int satisfy = 0;
        for(int j = i;j <= n - len; j += len)
        {
            string cur = s.substr(j,len);
            if(hash.find(cur) == hash.end())
                break;
            else
            {
                cur_hash[cur]++;
                if(cur_hash[cur] > hash[cur])
                    break;
                else if(cur_hash[cur] == hash[cur])
                    satisfy++;
                if(satisfy == hash.size())
                {
                    res.push_back(i);
                    break;
                }
            }
        }
    }
    return res;
}

vector<int> findSubstring1(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    vector<int> res;
    int n = s.size(), cnt = words.size(), len = words[0].size();
    unordered_map<string, int> m1;
    for (string w : words) ++m1[w];
    for (int i = 0; i < len; ++i) {
        int left = i, count = 0;
        unordered_map<string, int> m2;
        for (int j = i; j <= n - len; j += len) {
            string t = s.substr(j, len);
            if (m1.count(t)) {
                ++m2[t];
                if (m2[t] <= m1[t]) {
                    ++count;
                } else {
                    while (m2[t] > m1[t]) {
                        string t1 = s.substr(left, len);
                        --m2[t1];
                        if (m2[t1] < m1[t1]) --count;
                        left += len;
                    }
                }
                if (count == cnt) {
                    res.push_back(left);
                    --m2[s.substr(left, len)];
                    --count;
                    left += len;
                }
            } else {
                m2.clear();
                count = 0;
                left = j + len;
            }
        }
    }
    return res;
}

vector<int> substring(string s, vector<string>& words)
{
    if (s.empty() || words.empty())
        return {};

    int len = words[0].length(), cnt = words.size(), n = s.length();
    unordered_map<string, int> m1;
    vector<int> res;
    for (const string &w : words)
        m1[w]++;

    for (int i = 0; i < len; i++)
    {
        int left = i, count = 0;
        unordered_map<string, int> m2;
        for (int j = i; j <= n - len; j += len)
        {
            string t = s.substr(j, len);
            if (m1.count(t))
            {
                ++m2[t];
                if (m2[t] <= m1[t])
                    count++;
                else
                {
                    while (m2[t] > m1[t])
                    {
                        string t1 = s.substr(left, len);
                        --m2[t1];
                        if (m2[t1] < m1[t1])
                            --count;
                        left += len;
                    }
                }

                if (count == cnt)
                {
                    res.push_back(left);
                    --m2[s.substr(left, len)];
                    --count;
                    left += len;
                }
            }
            else
            {
                m2.clear();
                count = 0;
                left = j + len;
            }
        }
    }
    return res;
}