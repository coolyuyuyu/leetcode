class Solution {
public:
    int computeGCD(int x, int y) {
        while (x > 0) {
            int tmp = y % x;
            y = x;
            x = tmp;
        }

        return y;
    }

    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int gcd = nums[i];
            for (size_t j = i; j < nums.size(); ++j) {
                if (i < j) {
                    gcd = computeGCD(gcd, nums[j]);
                }

                if (gcd < k) {
                    break;
                }
                else if (gcd == k) {
                    cnt += 1;
                }
            }
        }

        return cnt;
    }
};
