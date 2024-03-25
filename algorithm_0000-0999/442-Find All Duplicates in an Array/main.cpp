class Solution {
public:
    // Time: O(N), Space: O(1), index sort
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        for (int i = 1; i <= n; ++i) {
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                std::swap(nums[i], nums[nums[i]]);
            }
        }

        vector<int> ret;
        for (int i = 1; i <= n; ++i) {
            if (nums[i] != i) {
                ret.push_back(nums[i]);
            }
        }

        return ret;
    }
};
