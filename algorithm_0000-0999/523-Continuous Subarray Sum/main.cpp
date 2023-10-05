class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> reminders({0});
        for (int i = 1, presum = nums[0]; i < nums.size(); ++i) {
            presum += nums[i];
            if (reminders.find(presum % k) != reminders.end()) {
                return true;
            }

            reminders.insert((presum - nums[i]) % k);
        }

        return false;
    }
};
