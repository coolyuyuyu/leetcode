class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        multiset<tuple<int, int, int>> ms; // num, row, col
        for (int r = 0; r < k; ++r) {
            ms.emplace(nums[r][0], r, 0);
        }

        vector<int> ret = {0, INT_MAX};
        while (ms.size() == k) {
            const auto& [minNum, _1, _2] = *ms.begin();
            const auto& [maxNum, _3, _4] = *ms.rbegin();
            if (maxNum - minNum < ret[1] - ret[0]) {
                ret = {minNum, maxNum};
            }

            auto [_, r, c] = *ms.begin();
            ms.erase(ms.begin());
            ++c;
            if (c < nums[r].size()) {
                ms.emplace(nums[r][c], r, c);
            }
        }

        return ret;
    }
};
