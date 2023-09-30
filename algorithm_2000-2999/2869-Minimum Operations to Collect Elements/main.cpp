class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i = 1; i <= k; ++i) {
            s.insert(i);
        }

        int ret = 0;
        for (int i = nums.size(); 0 < i-- && !s.empty();) {
            s.erase(nums[i]);
            ++ret;
        }

        return ret;
    }
};
