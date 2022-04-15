class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                sum += nums[i];
            }
        }
        return sum;
    }
};
