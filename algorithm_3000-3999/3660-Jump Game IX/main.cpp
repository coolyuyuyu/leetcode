class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        int preMax[n];
        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = std::max(preMax[i - 1], nums[i]);
        }

        int sufMin[n];
        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufMin[i] = std::min(sufMin[i + 1], nums[i]);
        }

        vector<int> ret(n);
        ret[n - 1] = preMax[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            ret[i] = preMax[i] > sufMin[i + 1] ? ret[i + 1] : preMax[i];
        }

        return ret;
    }
};
