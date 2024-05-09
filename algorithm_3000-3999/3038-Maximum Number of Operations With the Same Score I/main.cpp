class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];

        int ret = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != score) { break; }
            ++ret;
        }

        return ret;
    }
};
