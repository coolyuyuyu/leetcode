class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int cool = 0;
        for (int price : prices) {
            int tmpHold = hold, tmpSold = sold, tmpCool = cool;
            hold = std::max(tmpHold, cool - price);
            sold = tmpHold + price;
            cool = std::max(tmpCool, tmpSold);
        }

        return std::max(sold, cool);
    }
};
