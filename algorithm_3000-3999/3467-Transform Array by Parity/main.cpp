class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int cnt0 = 0;
        for (int num : nums) {
            cnt0 += ((num % 2) == 0);
        }

        vector<int> ret(nums.size(), 0);
        std::fill(ret.begin() + cnt0, ret.end(), 1);
        return ret;
    }
};
