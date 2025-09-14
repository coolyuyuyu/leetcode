class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        std::sort(nums.rbegin(), nums.rend());

        vector<int> ret;
        for (int i = 0, n = nums.size(); i < n && ret.size() < k; ++i) {
            if (ret.empty() || ret.back() > nums[i]) {
                ret.push_back(nums[i]);
            }
        }

        return ret;
    }
};
