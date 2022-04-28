class Solution {
public:
    // Time: O(N^2)
    int countQuadruplets(vector<int>& nums) {
        // a + c = d - c

        int cnt = 0;
        unordered_map<int, int> diffCnts = {{nums[nums.size() - 1] - nums[nums.size() - 2], 1}}; // cnt of diff of d - c
        for (size_t b = nums.size() - 2; 1 < b--;) {
            for (size_t a = b; 0 < a--;) {
                cnt += diffCnts[nums[a] + nums[b]];
            }

            for (int c = b, d = b + 1; d < nums.size(); ++d) {
                ++diffCnts[nums[d] - nums[c]];
            }
        }

        return cnt;
    }
};
