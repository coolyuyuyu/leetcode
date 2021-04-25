class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> counts(50, 0);
        for (int i = lowLimit; i <= highLimit; ++i) {
            int num = i;

            int sum = 0;
            while (num != 0) {
                sum += (num % 10);
                num /= 10;
            }
            ++counts[sum];
        }

        return *max_element(counts.begin(), counts.end());
    }
};
