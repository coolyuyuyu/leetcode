class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }

        int ret = 0;
        for (const auto& [_, indexes] : m) {
            for (int lft = 0, rht = 0, n = indexes.size(); lft < n; ++lft) {
                for (; rht < n && ((indexes[rht] - indexes[lft] + 1) - (rht - lft + 1) <= k); ++rht) {
                ;
                }

                ret = std::max(ret, rht - lft);
            }

        }

        return ret;
    }
};
