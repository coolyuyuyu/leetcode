class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0;
        unordered_map<int, int> cnts;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            ++cnts[nums[i]];
        }

        long long ret = 0;
        if (m <= cnts.size()) {
            ret = sum;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];

            --cnts[nums[i - k]];
            ++cnts[nums[i]];
            if (cnts[nums[i - k]] == 0) {
                cnts.erase(nums[i - k]);
            }

            if (m <= cnts.size()) {
                ret = std::max(ret, sum);
            }
        }

        return ret;
    }
};
