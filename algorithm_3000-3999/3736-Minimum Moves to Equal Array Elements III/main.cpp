class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());

        int ret = 0;
        for (int num : nums) {
            ret += mx - num;
        }

        return ret;
    }
};
