class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        assert(!candies.empty());
        int m = *std::max_element(candies.begin(), candies.end());
        if (m <= extraCandies) {
            return vector<bool>(candies.size(), true);
        }

        vector<bool> ans(candies.size());
        int remaining = m - extraCandies;
        for (size_t i = 0; i < candies.size(); ++i) {
            ans[i] = (remaining <= candies[i]);
        }

        return ans;
    }
};
