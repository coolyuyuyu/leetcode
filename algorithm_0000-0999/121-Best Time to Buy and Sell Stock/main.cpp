class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxGain = 0;
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

