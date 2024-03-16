class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int& num : nums) {
            if (num == 0) {
                num = -1;
            }
        }

        int ret = 0;
        unordered_map<int, int> presum2idx = {{0, -1}};
        for (int i = 0, presum = 0; i < nums.size(); ++i) {
            presum += nums[i];
            auto [itr, inserted] = presum2idx.emplace(presum, i);
            if (!inserted) {
                ret = std::max(ret, i - itr->second);
            }
        }

        return ret;
    }
};
