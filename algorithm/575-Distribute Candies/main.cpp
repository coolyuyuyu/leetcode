class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int maxCount = candies.size() / 2;

        unordered_set<int> candySet;
        for (int candy : candies) {
            candySet.insert(candy);

            if (candySet.size() >= maxCount) {
                return maxCount;
            }
        }

        return candySet.size();
    }
};