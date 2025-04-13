class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};
