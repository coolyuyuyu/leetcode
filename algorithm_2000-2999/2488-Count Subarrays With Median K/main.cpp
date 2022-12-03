class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for (int& num : nums) {
            if (num < k) {
                num = -1;
            }
            else if (num == k) {
                num = 0;
            }
            else {
                num = 1;
            }
        }

        unordered_map<int, int> presum_o, presum_e;
        // presum_o[s]: the number of prefix whose sum == s && length of prefix is odd
        // presum_e[s]: the number of prefix whose sum == s && length of prefix is even
        presum_e[0] = 1; // none of any prefix.

        int ret = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i & 1) { // even len
                ret += presum_o[sum];
                ret += presum_e[sum - 1];
                ++presum_e[sum];
            }
            else { // odd len
                ret += presum_e[sum];
                ret += presum_o[sum - 1];
                ++presum_o[sum];
            }
        }

        return ret;
    }
};
