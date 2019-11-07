//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-07.
//

void dfs(vector<int>& candidates, int sum, int index, int target, vector<vector<int>>& res, vector<int> tmp)
{
    if (sum == target) {
        res.push_back(tmp);
        return;
    }
    if (sum > target)
        return;
    int n = candidates.size();
    for (int i = index; i < n; ++i) {
        tmp.push_back(candidates[i]);
        dfs(candidates, sum + candidates[i], i, target, res, tmp);
        tmp.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> tmp;
    int n = candidates.size();
    dfs(candidates, 0, 0, target, res, tmp);
    return res;
}

vector<vector<int>> combinationSumAnotherVersion(const vector<int>& n, int target) {
    vector<int> factor(n.size());
    vector<vector<int>> res;
    int sum = 0;

    do {
        for (int i = 0; i < n.size(); i++) {
            if (sum + n[i] <= target) {
                sum += n[i];
                factor[i] += 1;
                break;
            }
            sum -= n[i] * factor[i];
            factor[i] = 0;
        }
        if (sum == target) {
            vector<int> tmp;
            for (int i = 0; i < factor.size(); i++) {
                for (int j = 0; j < factor[i]; j++)
                    tmp.push_back(n[i]);
            }
            res.push_back(move(tmp));
        }
    } while (sum > 0);
    return res;
}


