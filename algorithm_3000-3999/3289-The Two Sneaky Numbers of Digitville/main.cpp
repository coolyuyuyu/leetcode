class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> flags(nums.size() - 2, false);
        vector<int> ret;
        for (int num : nums) {
            if (flags[num]) {
                ret.push_back(num);
            }
            else {
                flags[num] = true;
            }
        }

        return ret;
    }
};
