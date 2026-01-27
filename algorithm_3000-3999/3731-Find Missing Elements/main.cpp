class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<int> ret;
        for (int i = 1; i < nums.size(); ++i) {
            for (int lo = nums[i - 1] + 1, hi = nums[i] - 1; lo <= hi; ++lo) {
                ret.push_back(lo);
            }
        }

        return ret;
    }
};
