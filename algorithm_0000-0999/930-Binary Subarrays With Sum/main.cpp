class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ret = 0;
        unordered_map<int, int> presum2cnt = {{0, 1}};
        for (int i = 0, sum = 0; i < nums.size();; ++i) {
            sum += nums[i];
            ret += presum2cnt[sum - goal];
            ++presum2cnt[sum];
        }

        return ret;
    }
};
