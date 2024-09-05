class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int sum = mean * (m + n);
        for (int roll : rolls) {
            sum -= roll;
        }
        if (sum < n || sum > n * 6) {
            return {};
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = sum / n + (i < (sum % n) ? 1 : 0);
        }

        return ret;
    }
};
