class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int partLen = n / k;
        for (int i = 0; i < n; i += partLen) {
            std::reverse(nums.begin() + i, nums.begin() + i + partLen);
        }

        return nums;
    }
};
