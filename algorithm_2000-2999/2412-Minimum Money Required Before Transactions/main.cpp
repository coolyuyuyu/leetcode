class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        std::sort(
            transactions.begin(), transactions.end(),
            [](const vector<int>& t1, const vector<int>& t2) {
                return t1[1] < t2[1];
            });

        long long capital = 0;
        long long recordLow = 0;
        long long maxCostOfGain = 0;
        for (const auto& t : transactions) {
            long long cost = t[0], back = t[1];
            if (back < cost) {
                capital -= cost;
                recordLow = std::min(recordLow, capital);
                capital += back;
            }
            else {
                maxCostOfGain = std::max(maxCostOfGain, cost);
            }
        }
        capital -= maxCostOfGain;
        recordLow = std::min(recordLow, capital);

        return -recordLow;
    }
};

// The order of the most difficult transaction sequence:
// X X X X X O O O O
// X: loss transaction (cost > cashback), rank by cashback in asscending order
// O: gain transaction (cost <= cashback), rank by cost in descending order
