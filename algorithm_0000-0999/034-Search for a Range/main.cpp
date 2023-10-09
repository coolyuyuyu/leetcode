class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       auto itr = std::lower_bound(nums.begin(), nums.end(), target);
       if (itr == nums.end() || *itr != target) {
           return {-1, -1};
       }
       else {
           int l = std::distance(nums.begin(), itr);
           int r = std::distance(nums.begin(), std::upper_bound(itr + 1, nums.end(), target)) - 1;
           return {l, r};
       }
    }
};
