class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, long long> num2presum;

        long long ret = LLONG_MIN;
        long long presum = 0;
        for (int i = 0; i < n; ++i) {
            auto itr1 = num2presum.find(nums[i] + k);
            if (itr1 != num2presum.end()) {
                ret = std::max(ret, presum + nums[i] - itr1->second);
            }
            auto itr2 = num2presum.find(nums[i] - k);
            if (itr2 != num2presum.end()) {
                ret = std::max(ret, presum + nums[i] - itr2->second);
            }

            auto [itr, inserted] = num2presum.emplace(nums[i], presum);
            if (!inserted) {
                itr->second = std::min(presum, itr->second);
            }

            presum += nums[i];
        }

        return ret == LLONG_MIN ? 0 : ret;
    }
};
