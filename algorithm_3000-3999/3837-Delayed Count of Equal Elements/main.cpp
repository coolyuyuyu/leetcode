class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ret(n);

        unordered_map<int, int> cnts;
        for (int i = n - 1; i >= 0; --i) {
            if (i + k  + 1< n) {
                ++cnts[nums[i + k + 1]];
            }
            ret[i] = cnts[nums[i]];
        }

        return ret;
    }
};
