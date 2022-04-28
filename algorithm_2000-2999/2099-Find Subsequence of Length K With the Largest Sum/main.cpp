class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        assert(0 < k);

        vector<int> tmp(nums);
        std::nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end(), std::greater<int>());
        int cnt = std::count(tmp.begin(), tmp.begin() + k, tmp[k - 1]);

        vector<int> ans;
        for (int num : nums) {
            if (tmp[k - 1] < num || (tmp[k - 1] == num && 0 < cnt--)) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
