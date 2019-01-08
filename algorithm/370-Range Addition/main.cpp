class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length, 0);
        for (size_t i = 0; i < updates.size(); ++i) {
            nums[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < nums.size()) {
                nums[updates[i][1] + 1] -= updates[i][2];
            }
        }
        partial_sum(nums.begin(), nums.end(), nums.begin());

        return nums;
    }
};