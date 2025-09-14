class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();

        vector<bool> seen(102, false);
        for (int num : nums) {
            if (num >= 1) {
                seen[num] = true;
            }
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        int ret = 1;
        while (seen[ret] || (ret * n <= sum)) {
            ++ret;
        }

        return ret;
    }
};
