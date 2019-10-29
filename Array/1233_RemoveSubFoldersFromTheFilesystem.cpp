//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-28.
//

vector<string> removeSubfolders(vector<string>& folder)
{
    unordered_set<string> mp(begin(folder), end(folder));
    vector<string> res;

    for (const auto& cur : folder) {
        bool valid = true;
        string s = cur;
        while (!s.empty() && valid) {
            while (s.back() != '/')
                s.pop_back();
            s.pop_back();
            if (mp.count(s))
                valid = false;
        }

        if (valid)
            res.push_back(cur);
    }
    return res;
}

vector<string> removeSubfolder(vector<string>& folder)
{
    sort(folder.begin(), folder.end());
    vector<string> ans;
    ans.push_back(folder[0]);
    for(int i = 1; i < folder.size(); ++i){
        string &a = folder[i];
        if(ans.back() == a.substr(0, ans.back().size()) && a[ans.back().size()] == '/');
        else
            ans.push_back(a);
    }
    return ans;
}
