class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int l = 0; l < n; ++l) {
            unordered_set<int> eSet, oSet;
            for (int r = l; r < n; ++r) {
                auto& s = (nums[r] & 1 ? oSet : eSet);
                s.insert(nums[r]);

                if (eSet.size() == oSet.size()) {
                    ret = std::max(ret, r - l + 1);
                }
            }
        }

        return ret;
    }
};
