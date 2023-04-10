class Solution {
public:
    bool checkPrime(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; (i * i) <= num; ++i) {
            if ((num % i) == 0) {
                return false;
            }
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (checkPrime(nums[i][i])) {
                ret = std::max(ret, nums[i][i]);
            }
            if (checkPrime(nums[i][n - i - 1])) {
                ret = std::max(ret, nums[i][n - i - 1] );
            }
        }

        return ret;
    }
};
