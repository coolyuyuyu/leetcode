class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int p = 0;
        while (p + 1 < n && nums[p] < nums[p + 1]) { ++p; }
        if (p == 0 || p >= n - 2) {
            return false;
        }

        int q = p;
        while (q + 1 < n && nums[q] > nums[q + 1]) { ++q; }
        if (p == q || q == n - 1) {
            return false;
        }

        int i = q;
        while (i + 1 < n && nums[i] < nums[i + 1]) { ++i; }
        if (q == i || i != n - 1) {
            return false;
        }

        return true;
    }
};
