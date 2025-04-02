class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return 0;
        }
        else if (n % 2 == 1) {
            return std::accumulate(nums.begin(), nums.end(), 0) - *std::min_element(nums.begin(), nums.end());
        }
        else {
            int x = INT_MAX;
            for (int i = 1; i < n; ++i) {
                x = std::min(x, nums[i - 1] + nums[i]);
            }
            return std::accumulate(nums.begin(), nums.end(), 0) - x;
        }
    }
};
