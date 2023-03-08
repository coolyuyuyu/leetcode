class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size() && (far + 1) < nums.size(); ++i) {
            if (far < i) {
                return false;
            }
            far = std::max(far, i + nums[i]);
        }

        return true;
    }
};
