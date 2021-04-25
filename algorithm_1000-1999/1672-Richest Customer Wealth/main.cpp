class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxAmount = 0;
        for (const vector<int>& account : accounts) {
            int amount = accumulate(account.begin(), account.end(), 0);
            if (maxAmount < amount) {
                maxAmount = amount;
            }
        }

        return maxAmount;
    }
};
