class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int minVal = *std::min_element(nums.begin(), nums.end());
        for (int num : nums) {
            if (num % minVal != 0) {
                return 1;
            }
        }

        int minCnt = std::count(nums.begin(), nums.end(), minVal);
        return (minCnt + 1) / 2;
    }
};
