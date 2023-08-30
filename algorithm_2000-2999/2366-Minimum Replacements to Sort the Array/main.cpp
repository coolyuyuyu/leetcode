class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();

        long long ret = 0;
        for (int i = n - 2; 0 <= i; --i) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            int k = nums[i] / nums[i + 1]  + (nums[i] % nums[i + 1] ? 1 : 0);
            ret += k - 1;
            nums[i] /= k;
        }

        return ret;
    }
};
