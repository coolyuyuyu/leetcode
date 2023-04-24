class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *std::max_element(candies.begin(), candies.end());

        vector<bool> ret(candies.size());
        int threshold = m - extraCandies;
        for (int i = 0; i < candies.size(); ++i) {
            ret[i] = (threshold <= candies[i]);
        }

        return ret;
    }
};
