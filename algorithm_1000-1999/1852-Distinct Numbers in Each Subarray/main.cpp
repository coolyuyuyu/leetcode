class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> cnts;
        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            ++cnts[nums[i]];
            if (i + 1 >= k) {
                ret[i + 1 - k] = cnts.size();
                if (--cnts[nums[i + 1 - k]] == 0) {
                    cnts.erase(nums[i + 1 - k]);
                }
            }
        }

        return ret;
    }
};
