class Solution {
public:
    int f1(vector<int>& nums) {
        // Kadane
        int ret = 0;
        for (int i = 0, mn = 0, mx = 0; i < nums.size(); ++i) {
            mn = std::min(nums[i], mn + nums[i]);
            mx = std::max(nums[i], mx + nums[i]);
            ret = std::max({ret, abs(mn), abs(mx)});
        }

        return ret;
    }

    int f2(vector<int>& nums) {
        // max |sum[i:j]|
        // => max |presum[j] - presum[i - 1]|
        // => max(presum[j] - presum[i - 1], presum[i - 1] - presum[j])
        int presumMN = 0, presumMX = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            presumMN = std::min(presumMN, sum);
            presumMX = std::max(presumMX, sum);
        }

        return presumMX - presumMN;
    }

    int maxAbsoluteSum(vector<int>& nums) {
       //return f1(nums);
       return f2(nums);
    }
};
