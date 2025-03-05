class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ret(n);
        int lft = 0, rht = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                ret[lft++] = nums[i];
            }
        }
        for (int i = n; 0 < i--;) {
            if (nums[i] > pivot) {
                ret[rht--] = nums[i];
            }
        }
        std::fill(ret.begin() + lft, ret.begin() + rht + 1, pivot);

        return ret;
    }
};
