class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int sum = 0;
            unordered_set<int> s;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                s.insert(nums[j]);

                if (s.find(sum) != s.end()) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
