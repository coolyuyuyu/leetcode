class Solution {
public:
    double average(vector<int>& salary) {
        int maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max();
        int sum = 0;
        for (int num : salary) {
            sum += num;

            if (maxVal < num) {
                maxVal = num;
            }
            if (num < minVal) {
                minVal = num;
            }
        }

        sum -= (maxVal + minVal);
        return (static_cast<double>(sum) / (salary.size() - 2));
    }
};
