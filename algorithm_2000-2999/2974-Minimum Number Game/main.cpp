class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            std::swap(nums[i], nums[i + 1]);
        }

        return nums;
    }
};
