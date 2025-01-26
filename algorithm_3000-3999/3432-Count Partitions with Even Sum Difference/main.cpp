class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int total = std::accumulate(nums.begin(), nums.end(), 0);

        int ret = 0;
        for (int i = 0, lft = 0, rht = total; i + 1 < n; ++i) {
            lft += nums[i], rht -= nums[i];
            if ((lft - rht) % 2 == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
