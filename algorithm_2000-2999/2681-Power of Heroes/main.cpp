class Solution {
public:
    long long M = 1e9 + 7;

    int sumOfPower(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        long long ret = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            long long square = (static_cast<long long>(nums[i]) * nums[i]) % M;
            ret += (square * (sum + nums[i]));
            ret %= M;

            sum = sum * 2 + nums[i];
            sum %= M;
        }

        return ret;
    }
};

// sorted: 1 2 4 7
// i = 0
//     nums[0]^2 * (0) + nums[0]^3
// i = 1
//     nums[1]^2 * (nums[0] * 1) + nums[1]^3
// i = 2
//     nums[2]^2 * (nums[0] * 2 + nums[1] * 1) +nums[2]^３
// i = 3
//     nums[3]^2 * (nums[0] * 4 + nums[1] * 2 + nums[2] * 1) + nums[3]^3
