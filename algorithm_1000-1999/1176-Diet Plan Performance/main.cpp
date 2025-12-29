class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int ret = 0;
        for (int i = 0, n = calories.size(), sum = 0; i < n; ++i) {
            sum += calories[i];
            if (i + 1 >= k) {
                if (sum < lower) {
                    ret -= 1;
                }
                else if (sum > upper) {
                    ret += 1;
                }

                sum -= calories[i + 1 - k];
            }
        }

        return ret;
    }
};
