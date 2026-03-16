class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;

        unordered_map<int, int> presum2cnt;
        int presum = 0;
        for (int num : nums) {
            presum += num;
            if (presum == k) {
                ++ret;
            }

            auto itr = presum2cnt.find(presum - k);
            if (itr != presum2cnt.end()) {
                ret += itr->second;
            }

            ++presum2cnt[presum];
        }

        return ret;
    }
};
