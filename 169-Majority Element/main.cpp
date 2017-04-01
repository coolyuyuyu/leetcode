class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            major == nums[i] ? ++count : --count;
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
        }
        return major;
    }
};