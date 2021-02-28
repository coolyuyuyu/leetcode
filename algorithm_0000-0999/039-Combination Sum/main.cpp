class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int target, int begin, vector<int>& result, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(result);
        }
        else {
            for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
                result.push_back(candidates[i]);
                combinationSumHelper(candidates, target - candidates[i], i, result, results);
                result.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> result;
        vector<vector<int>> results;
        combinationSumHelper(candidates, target, 0, result, results);
        return results;
    }
};