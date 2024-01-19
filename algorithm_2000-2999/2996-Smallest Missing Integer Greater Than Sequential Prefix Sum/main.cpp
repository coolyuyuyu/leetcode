class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seqPreSum = nums[0];
        for (int i = 1; i < nums.size() && nums[i - 1] + 1 == nums[i]; ++i) {
            seqPreSum += nums[i];
        }

        vector<bool> s(2501);
        for (int num : nums) {
            s[num] = true;
        }

        int ret = seqPreSum;
        while (s[ret]) {
            ++ret;
        }

        return ret;
    }
};
