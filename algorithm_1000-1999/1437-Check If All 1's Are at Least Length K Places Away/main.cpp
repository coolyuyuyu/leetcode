class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for (int i = 0, n = nums.size(), pre = -k - 1; i < n; ++i) {
            if (nums[i] == 1) {
                if (i - pre - 1 < k) {
                    return false;
                } 
                pre = i;
            }
        }

        return true;
    }
};
