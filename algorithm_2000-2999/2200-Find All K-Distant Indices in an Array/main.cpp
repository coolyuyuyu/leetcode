class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                int bgn = std::max(i - k, ans.empty() ? 0 : (ans.back() + 1));
                int end = std::min(i + k + 1, int(nums.size()));
                for (int j = bgn; j < end; ++j) {
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};
