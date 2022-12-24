class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0, cd = 0;
        for (int price : prices) {
            int holdPre = hold;
            int soldPre = sold;
            int cdPre = cd;

            hold = std::max(holdPre, cdPre - price);
            sold = holdPre + price;
            cd = std::max(cdPre, soldPre);
        }

        return std::max(sold, cd);
    }
};
