class Solution {
public:
    void permuteRecv1(vector<int>& nums, vector<bool>& used, vector<int>& perm, vector<vector<int>>& ans) {
        if (nums.size() <= perm.size()) {
            ans.push_back(perm);
        }
        else {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (used[i]) {
                    continue;
                }

                used[i] = true;
                perm.push_back(nums[i]);
                permuteRecv1(nums, used, perm, ans);
                used[i] = false;
                perm.pop_back();
            }
        }
    }

    void permuteRecv2(vector<int>& nums, size_t index, vector<vector<int>>& ans) {
        if (nums.size() <= index) {
            ans.push_back(nums);
        }
        else {
            for (size_t i = index; i < nums.size(); ++i) {
                swap(nums[index], nums[i]);
                permuteRecv2(nums, index + 1, ans);
                swap(nums[index], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        // vector<bool> used(nums.size(), false);
        // vector<int> perm;
        // perm.reserve(nums.size());
        // permuteRecv1(nums, used, perm, ans);

        permuteRecv2(nums, 0, ans);

        return ans;
    }
};