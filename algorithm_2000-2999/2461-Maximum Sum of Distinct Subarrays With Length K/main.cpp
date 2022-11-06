class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<size_t> cnts(*std::max_element(nums.begin(), nums.end()) + 1, 0);
        size_t dupCnt = 0;
        for (size_t i = 0; i < k; ++i) {
            sum += nums[i];

            if (cnts[nums[i]] == 1) {
                ++dupCnt;
            }
            ++cnts[nums[i]];
        }

        long long ans = (dupCnt == 0 ? sum : 0);
        for (size_t i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];

            --cnts[nums[i - k]];
            if (cnts[nums[i - k]] == 1) {
                --dupCnt;
            }

            if (cnts[nums[i]] == 1) {
                ++dupCnt;
            }
            ++cnts[nums[i]];

            if (dupCnt == 0 && ans < sum) {
                ans = sum;
            }
        }

        return ans;
    }
};
