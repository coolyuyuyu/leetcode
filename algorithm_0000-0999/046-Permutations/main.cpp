class Solution {
public:
    void permuteRecv1(vector<int>& nums, vector<bool>& used, vector<int>& result, vector<vector<int>>& results) {
        if (nums.size() <= result.size()) {
            results.push_back(result);
        }
        else {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (used[i]) {
                    continue;
                }

                used[i] = true;
                result.push_back(nums[i]);
                permuteRecv1(nums, used, result, results);
                used[i] = false;
                result.pop_back();
            }
        }
    }

    void permuteRecv2(vector<int>& nums, size_t index, vector<vector<int>>& results) {
        if (nums.size() <= index) {
            results.push_back(nums);
        }
        else {
            for (size_t i = index; i < nums.size(); ++i) {
                swap(nums[index], nums[i]);
                permuteRecv2(nums, index + 1, results);
                swap(nums[index], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;

        // vector<bool> used(nums.size(), false);
        // vector<int> result;
        // result.reserve(nums.size());
        // permuteRecv1(nums, used, result, results);

        permuteRecv2(nums, 0, results);

        return results;
    }
};