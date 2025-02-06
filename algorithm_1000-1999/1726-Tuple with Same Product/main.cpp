class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> cnts;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++cnts[nums[i] * nums[j]];
            }
        }

        int ret = 0;
        for (const auto&[_, cnt] : cnts) {
            ret += cnt * (cnt - 1) / 2 * 8;
        }

        return ret;
    }
};
