class Solution {
public:
    int M = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> powers(n);
        powers[0] = 1;
        for (int i = 1; i < n; ++i) {
            powers[i] = powers[i - 1] * 2 % M;
        }

        int ret = 0;
        for (int i = 0, j = n; i < n; ++i) {
            while (i < j && target < (nums[i] + nums[j - 1])) {
                j--;
            }

            if (j <= i) {
                break;
            }　

            ret = (ret + powers[j - i - 1]) % M;
        }

        return ret;
    }
};
