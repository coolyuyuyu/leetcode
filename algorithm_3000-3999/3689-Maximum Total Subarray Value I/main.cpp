class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto p = std::minmax_element(nums.begin(), nums.end());
        int mn = *(p.first), mx = *(p.second);
        return (0L + mx - mn) * k;
    }
};
