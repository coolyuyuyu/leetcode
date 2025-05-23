class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int diffs[n + 1];
        std::fill(diffs, diffs + n + 1, 0);

        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ++diffs[l];
            --diffs[r + 1];
        }

        for (int i = 0, sum = 0; i < n; ++i) {
            sum += diffs[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
