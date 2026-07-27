class Solution {
public:
    int findGCD(vector<int>& nums) {
        const auto [itrMin, itrMax] = std::minmax_element(nums.begin(), nums.end());
        return std::gcd(*itrMin, *itrMax);
    }
};
