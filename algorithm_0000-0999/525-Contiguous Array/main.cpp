class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        size_t n = nums.size();

        for (auto& num : nums) {
            if (num == 0) {
                num = -1;
            }
        }

        int ret = 0;
        unordered_map<int, int> m; // presum -> smallest index
        m[0] = -1;
        for (int presum = 0, i = 0; i < n; ++i) {
            presum += nums[i];
            auto p = m.emplace(presum, i);
            if (p.second == false) {
                ret = std::max(ret, i - p.first->second);
            }
        }

        return ret;
    }
};

/*
X X X X X X X
    j       i
presum[i] - prefix[j] = sum(j+1:i) = 0
=> presum[i] = presum[j], len = i - j
*/
