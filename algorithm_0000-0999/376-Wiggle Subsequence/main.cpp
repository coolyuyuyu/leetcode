class Solution {
public:
    int greedy(const vector<int>& nums) {
        // -1: minus, 0: 0, 1: plus, -2: initial default
        int slope = -2;

        int ret = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int preSlope = slope;
            if ((nums[i] - nums[i - 1]) < 0) {
                slope = -1;
            }
            else if ((nums[i] - nums[i - 1]) == 0) {
                slope = preSlope;
            }
            else {
                slope = 1;
            }

            if (slope != preSlope) {
                ++ret;
            }
        }

        return ret;
    }

    int dp(const vector<int>& nums) {
        int up = 1; // up[i]: the length of the longest wiggle subsequence of nums[0:i] and last segment goes up
        int dn = 1; // dn[i]: the length of the longest wiggle subsequence of nums[0:i] and last segment goes down
        for (int i = 1; i < nums.size(); ++i) {
            if ((nums[i] - nums[i - 1]) < 0) {
                dn = up + 1;
            }
            else if (0 < (nums[i] - nums[i - 1])) {
                up = dn + 1;
            }
        }

        return std::max(up, dn);
    }

    int wiggleMaxLength(vector<int>& nums) {
        //return greedy(nums);
        return dp(nums);
    }
};
