class Solution {
public:
    int greedy(const vector<int>& nums) {
        // -1: negative
        //  0: default
        //  1: positive
        int slope = 0;

        int ret = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int pre = slope;
            if (nums[i - 1] < nums[i]) {
                slope = 1;
            }
            else if (nums[i - 1] > nums[i]) {
                slope = -1;
            }

            if (slope != pre) {
                ++ret;
            }
        }

        return ret;
    }

    int dp(const vector<int>& nums) {
        int dn = 1; // dn[i]: the length of the longest wiggle subsequence of nums[0:i] and the last segment goes down
        int up = 1; // up[i]: the length of the longest wiggle subsequence of nums[0:i] and the last segment goes up
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                up = dn + 1;
            }
            else if (nums[i - 1] > nums[i]) {
                dn = up + 1;
            }
        }

        return std::max(dn, up);
    }

    int wiggleMaxLength(vector<int>& nums) {
        //return greedy(nums);
        return dp(nums);
    }
};
