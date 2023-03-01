class Solution {
public:
    void recursive(const vector<int>& candidates, int target, int index, vector<int>& comb, vector<vector<int>>& combs) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            combs.push_back(comb);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            comb.push_back(candidates[i]);
            recursive(candidates, target - candidates[i], i, comb, combs);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> combs;
        recursive(candidates, target, 0, comb, combs);
        return combs;
    }
};
