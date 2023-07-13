class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> diffs(n + 1, 0);
        for (int base = 0, i = 0; i < n; ++i) {
            base += diffs[i];
            int delta = nums[i] - base;
            if (delta < 0) {
                return false;
            }

            if (0 < delta) {
                if (n < i + k) {
                    return false;
                }

                diffs[i] += delta;
                diffs[i + k] -= delta;
                base += delta;
            }
        }

        return true;
    }
};
