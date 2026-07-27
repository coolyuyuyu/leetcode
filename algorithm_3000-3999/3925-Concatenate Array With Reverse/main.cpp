class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ret(nums);\
        std::copy(nums.rbegin(), nums.rend(), std::back_inserter(ret));
        return ret;
    }
};
