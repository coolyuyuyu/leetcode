class Solution {
public:
    int dp1(size_t n) {
        if (n == 0) {
            return 0;
        }
        else if (n < 3) {
            return 1;
        }

        vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = nums[2] = 1;
        for (size_t i = 3; i < nums.size(); ++i) {
            nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
        }

        return nums.back();
    }

    int dp2(size_t n) {
        if (n == 0) {
            return 0;
        }
        else if (n < 3) {
            return 1;
        }

        int x = 0, y = 1, z = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = x + y + z;
            x = y;
            y = z;
            z = tmp;
        }

        return z;
    }

    int tribonacci(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
