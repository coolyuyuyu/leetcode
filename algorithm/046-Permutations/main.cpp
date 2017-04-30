class Solution {
public:
    void permuteHelper(vector<int>& nums, int begin, vector<vector<int>>& results) {
        if (nums.size() <= begin) {
            results.push_back(nums);
        }
        else {
            for (int i = begin; i < nums.size(); ++i) {
                swap(nums[begin], nums[i]);
                permuteHelper(nums, begin + 1, results);
                swap(nums[begin], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        permuteHelper(nums, 0, results);
        return results;
    }
};