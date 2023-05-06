class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int minPrice = INT_MAX;
        for (int price : prices) {
            ret = std::max(ret, price - minPrice);
            minPrice = std::min(minPrice, price);
        }

        return ret;
    }
};
