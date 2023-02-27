class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ret = 0;
        for (int price : prices) {
            ret = std::max(ret, price - minPrice);
            minPrice = std::min(minPrice, price);
        }

        return ret;
    }
};
