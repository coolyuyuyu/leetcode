class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> findDuplicates_CycleSort(vector<int>& nums) {
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != (i + 1)) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }

    // Time: O(n), Space: O(1)
    vector<int> findDuplicates_Linear(vector<int>& nums) {
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] *= -1;
            if (0 < nums[abs(nums[i]) - 1] ) {
                ans.push_back(abs(nums[i]));
            }
        }

        return ans;
    }

    vector<int> findDuplicates(vector<int>& nums) {
        //return findDuplicates_CycleSort(nums);
        return findDuplicates_Linear(nums);
    }
};
