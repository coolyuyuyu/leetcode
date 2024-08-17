class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        vector<vector<int>> combs;
        vector<int> comb;
        std::function<void(int, int)> dfs = [&](int idx, int sum) {
            if (sum >= target) {
                if (sum == target) {
                    combs.push_back(comb);
                }
                return;
            }

            for (int i = idx; i < candidates.size(); ++i) {
                if (i > idx && candidates[i - 1] == candidates[i]) {
                    continue;
                }
                comb.push_back(candidates[i]);
                dfs(i + 1, sum + candidates[i]);
                comb.pop_back();
            }
        };

        dfs(0, 0);

        return combs;
    }
};
