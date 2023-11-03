class Solution {
public:
    double average(vector<int>& salary) {
        int maxVal = INT_MIN, minVal = INT_MAX, sumVal = 0;
        for (int val : salary) {
            maxVal = std::max(maxVal, val);
            minVal = std::min(minVal, val);
            sumVal += val;
        }

        return (sumVal - maxVal - minVal) * 1.0 / (salary.size() - 2);
    }
};
