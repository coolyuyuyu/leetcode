class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ret = 0;
        for (int i = 0, minIdx = -1, maxIdx = -1, bound = -1; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                bound = i;
                continue;
            }

            if (nums[i] == minK) {
                minIdx = i;
            }
            if (nums[i] == maxK) {
                maxIdx = i;
            }

            ret += std::max(std::min(minIdx, maxIdx) - bound, 0);
        }

        return ret;

    }
};
