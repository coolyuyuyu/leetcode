class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ret = 0;
        for (int boundary = -1, preMin = -1, preMax = -1, i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || maxK < nums[i]) {
                boundary = i;
                continue;
            }
            if (nums[i] == minK) {
                preMin = i;
            }
            if (nums[i] == maxK) {
                preMax = i;
            }

            ret += std::max(0, (std::min(preMin, preMax) - boundary));
        }

        return ret;
    }
};
