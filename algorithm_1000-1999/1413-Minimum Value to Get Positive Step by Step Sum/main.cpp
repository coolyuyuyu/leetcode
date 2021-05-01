class Solution {
public:
    int minStartValue(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minVal = *min_element(nums.begin(), nums.end());
        return (1 - (minVal < 0 ? minVal : 0));
    }
};
