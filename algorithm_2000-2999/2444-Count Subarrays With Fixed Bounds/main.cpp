class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // For each index i, count number of subarray ending at i.

        long long ret = 0;
        for (int i = 0, preMin = -1, preMax = -1, boundary = -1; i < nums.size(); ++i) {
            if (nums[i] < minK || maxK < nums[i]) {
                boundary = i;
                continue;
            }
            else if (nums[i] == minK) {
                preMin = i;
                if (nums[i] == maxK) {
                    preMax = i;
                }
            }
            else if (nums[i] == maxK) {
                preMax = i;
            }

            ret += (std::max(0, std::min(preMin, preMax) - boundary));
        }

        return ret;
    }
};
