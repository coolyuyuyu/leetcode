class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);

                ret += s.size() * s.size();
            }
        }

        return ret;
    }
};
