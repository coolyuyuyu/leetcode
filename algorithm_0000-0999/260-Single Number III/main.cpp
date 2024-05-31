class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        int s = sum & (sum * 1L - 1); // clear the least significant 1 bit
        int t = s ^ sum;

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & t) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        return {a, b};
    }
};
