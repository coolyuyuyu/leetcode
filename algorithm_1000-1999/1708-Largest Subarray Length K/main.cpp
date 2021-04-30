class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        vector<int>::iterator itr = max_element(nums.begin(), nums.end() - k + 1);
        return vector<int>(itr, itr + k);
    }
};
