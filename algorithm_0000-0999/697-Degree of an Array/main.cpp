class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        size_t minLen = 0;
        unordered_map<int, pair<size_t, size_t>> m; // val -> [first index, count]
        for (size_t maxCnt = 0, i = 0; i < nums.size(); ++i) {
            auto p = m.emplace(nums[i], pair<size_t, size_t>{i, 1});
            auto itr = p.first;
            if (!p.second) {
                ++(itr->second.second);
            }

            if (maxCnt < itr->second.second) {
                maxCnt = itr->second.second;
                minLen = i - itr->second.first + 1;
            }
            else if (maxCnt == itr->second.second) {
                minLen = std::min(minLen, i - itr->second.first + 1);
            }
        }

        return minLen;
    }
};
