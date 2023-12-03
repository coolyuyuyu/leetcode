class Solution {
public:
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0, j = n - 1; i <= j; ++i) {
            while (i <= j && nums[i] + nums[j] > target) {
                --j;
            }
            if (i > j) { break; }

            // QuickPow
            int cnt = 1;
            for (long exp = j - i, base = 2; exp; exp >>= 1) {
                if (exp & 1) {
                    cnt = (cnt * base) % M;
                }
                base = (base * base) % M;
            }

            ret = (ret +  cnt) % M;
        }

        return ret;
    }
};
