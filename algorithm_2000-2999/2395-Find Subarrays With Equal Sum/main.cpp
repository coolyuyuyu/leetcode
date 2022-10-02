class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (sums.insert(nums[i - 1] + nums[i]).second == false) {
                return true;
            }
        }

        return false;
    }
};
