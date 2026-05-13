class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int lftMax[n];
        lftMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            lftMax[i] = std::max(lftMax[i - 1], nums[i]);
        }

        int rhtMin[n];
        rhtMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rhtMin[i] = std::min(nums[i], rhtMin[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (lftMax[i] - rhtMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
