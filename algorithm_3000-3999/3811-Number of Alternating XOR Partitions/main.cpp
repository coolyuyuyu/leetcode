class Solution {
public:
    int M = 1e9 + 7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int dp1 = 0; // dp1[i]: the number of split from nums[0:i] where the xor sum of last block is target1
        int dp2 = 0; // dp2[i]: the number of split from nums[0:i] where the xor sum of last block is target2

        std::unordered_map<int, int> map1; // presum -> the number of ways of split where the xor sum of last block is target1
        std::unordered_map<int, int> map2; // presum -> the number of ways of split where the xor sum of last block is target2

        int sum = 0;
        for (int num : nums) {
            sum ^= num;

            int tmp1 = map2[sum ^ target1];
            if (sum == target1) {
                tmp1 = (tmp1 + 1) % M;
            }
            int tmp2 = map1[sum ^ target2];

            map1[sum] = (map1[sum] + tmp1) % M;
            map2[sum] = (map2[sum] + tmp2) % M;

            dp1 = tmp1;
            dp2 = tmp2;
        }

        return (dp1 + dp2) % M;
    }
};
