class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        map<int, int> counts;
        for (int num : nums) {
            ++counts[num];
        }

        int ans = 0;
        auto preItr = counts.begin();
        auto curItr = preItr; ++curItr;
        while (curItr != counts.end()) {
            if (preItr->first + 1 == curItr->first) {
                ans = max(ans, preItr->second + curItr->second);
            }

            preItr = curItr;
            ++curItr;
        }

        return ans;
    }
};