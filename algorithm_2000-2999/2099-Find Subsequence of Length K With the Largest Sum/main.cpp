class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> tmps(nums);
        std::nth_element(tmps.begin(), tmps.begin() + k - 1, tmps.end(), std::greater<int>());
        int pivot = tmps[k - 1];
        int cnt = std::count(tmps.begin(), tmps.begin() + k, pivot);

        vector<int> ret;
        for (int num : nums) {
            if (num > pivot || (num == pivot && cnt-- > 0)) {
                ret.push_back(num);
            }
        }

        return ret;
    }
};
