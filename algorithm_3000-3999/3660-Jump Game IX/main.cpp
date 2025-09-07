class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n), sufMin(n);
        for (int i = 0; i < n; ++i) {
            preMax[i] = i > 0 ? std::max(nums[i], preMax[i - 1]) : nums[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            sufMin[i] = i + 1 < n ? std::min(nums[i], sufMin[i + 1]) : nums[i];
        }

        vector<int> ret(n);
        ret[n - 1] = preMax[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (preMax[i] > sufMin[i + 1]) {
                ret[i] = ret[i + 1];
            }
            else {
                ret[i] = preMax[i];
            }
        }

        return ret;
    }
};
