class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_set<int> sums;
        for (size_t i = 0; (i * 2) < nums.size(); ++i) {
            sums.insert(nums[i] + nums[nums.size() - i - 1]);
        }

        return sums.size();
    }
};
