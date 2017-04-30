class Solution {
public:
    void permuteUniqueHelper(vector<int>& nums, int begin, vector<vector<int>>& results) {
        if (nums.size() <= begin) {
            results.push_back(nums);
        }
        else {
            unordered_set<int> used;
            for (int i = begin; i < nums.size(); ++i) {
                pair<unordered_set<int>::iterator, bool> p = used.insert(nums[i]);
                if (!p.second) {
                    continue;
                }

                swap(nums[begin], nums[i]);
                permuteUniqueHelper(nums, begin + 1, results);
                swap(nums[begin], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        permuteUniqueHelper(nums, 0, results);
        return results;
    }
};