class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            ++cnts[nums[i]];
        }

        long ret = 0;
        if (cnts.size() == k) {
            ret = sum;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            if (--cnts[nums[i - k]] == 0) {
                cnts.erase(nums[i - k]);
            }
            sum += nums[i];
            ++cnts[nums[i]];

            if (cnts.size() == k) {
                ret = std::max(ret, sum);
            }
        }

        return ret;
    }
};
