class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        double remaining = income;
        for (size_t i = 0; i < brackets.size(); ++i) {
            double maxAmount = (i == 0 ? brackets[i][0] : (brackets[i][0] - brackets[i - 1][0]));
            double amount = std::min(remaining, maxAmount);

            tax += amount* brackets[i][1] / 100;
            remaining -= amount;
        }
        return tax;
    }
};
