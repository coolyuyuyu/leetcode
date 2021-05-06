class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int cal = 0;
        for (int i = 0; (i + 1) < k; ++i) {
            cal += calories[i];
        }

        int points = 0;
        for (size_t i = k - 1; i < calories.size(); ++i) {
            cal += calories[i];

            if (cal < lower) {
                --points;
            }
            else if (upper < cal) {
                ++points;
            }

            cal -= calories[i + 1 - k];
        }

        return points;
    }
};
