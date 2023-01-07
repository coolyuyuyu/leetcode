class Solution {
public:
    // two pointers
    int minimumOperations(vector<int>& nums) {
        int ret = 0;
        long lftSum = nums.front(), rhtSum = nums.back();
        for (int lft = 0, rht = nums.size() - 1; lft < rht;) {
            if (lftSum == rhtSum) {
                lftSum = nums[++lft];
                rhtSum = nums[--rht];
            }
            else if (lftSum < rhtSum) {
                lftSum += nums[++lft];
                ++ret;
            }
            else {
                rhtSum += nums[--rht];
                ++ret;
            }
        }

        return ret;
    }
};
