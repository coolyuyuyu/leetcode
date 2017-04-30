class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target, int left, int begin, vector<int>& result, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(result);
        }
        else {
            if (target <= left) {
                for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
                    if (i && candidates[i] == candidates[i - 1] && begin < i) {
                        continue;
                    }

                    result.push_back(candidates[i]);
                    combinationSum2Helper(candidates, target - candidates[i], left - candidates[i], i + 1, result, results);
                    result.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int left = accumulate(candidates.begin(), candidates.end(), 0);
        vector<int> result;
        vector<vector<int>> results;
        combinationSum2Helper(candidates, target, left, 0, result, results);
        return results;
    }
};