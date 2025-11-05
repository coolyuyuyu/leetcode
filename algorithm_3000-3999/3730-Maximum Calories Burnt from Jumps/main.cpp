class Solution {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        std::sort(heights.begin(), heights.end());

        long long ret = 1LL * heights.back() * heights.back();
        for (int lft = 0, rht = heights.size() - 1; lft < rht;) {
            ret += 1LL * (heights[rht] - heights[lft]) * (heights[rht] - heights[lft]);
            --rht;
            if (lft < rht) {
                ret += 1LL * (heights[rht] - heights[lft]) * (heights[rht] - heights[lft]);
                ++lft;
            }
        }

        return ret;
    }
};
