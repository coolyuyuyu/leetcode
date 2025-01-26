class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ret = 0;
        for (int v = 1; v <= 50; ++v) {
            int mx = 0, cur = 0;
            for (int num : nums) {
                cur += (num == v ? 1 : 0);
                cur -= (num == k ? 1 : 0);
                cur = std::max(0, cur);
                mx = std::max(mx, cur);
            }
            ret = std::max(ret, mx);
        }

        return ret + std::count(nums.begin(), nums.end(), k);
    }
};
