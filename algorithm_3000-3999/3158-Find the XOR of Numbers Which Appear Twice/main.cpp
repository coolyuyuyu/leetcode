class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ret = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());

        unordered_set<int> s(nums.begin(), nums.end());
        ret = std::accumulate(s.begin(), s.end(), ret, std::bit_xor<int>());

        return ret;
    }
};
