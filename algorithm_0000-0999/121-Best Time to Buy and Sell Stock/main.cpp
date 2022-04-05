class Solution {
public:
    int maxProfit(vector<int>& prices) {
        assert(!prices.empty());

        int minPrice = std::numeric_limits<int>::max();
        int maxGain = 0;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }

            int gain = price - minPrice;
            if (maxGain < gain) {
                maxGain = gain;
            }
        }

        return maxGain;
    }
};
