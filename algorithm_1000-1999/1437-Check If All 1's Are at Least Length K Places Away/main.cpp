class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if (k == 0) {
            return true;
        }

        size_t pre = std::find(nums.begin(), nums.end(), 1) - nums.begin();
        for (size_t i = pre + 1; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if ((i - pre - 1) < k) {
                    return false;
                }
                pre = i;
            }
        }

        return true;
    }
};
