class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> sum1(n);
        sum1[0] = (customers[0] == 'N' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            sum1[i] = sum1[i - 1] + (customers[i] == 'N' ? 1 : 0);
        }

        vector<int> sum2(n);
        sum2[n - 1] = (customers[n - 1] == 'Y' ? 1 : 0);
        for (int i = n - 2; 0 <= i; --i) {
            sum2[i] = sum2[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int minPenality = INT_MAX;
        int ret;
        for (int i = 0; i <= n; ++i) {
            int penality = (0 < i ? sum1[i - 1] : 0) + (i < n ? sum2[i] : 0);
            if (penality < minPenality) {
                minPenality = penality;
                ret = i;
            }
        }

        return ret;
    }
};
