class Solution {
public:
    double average(vector<int>& salary) {
        int sumVal = 0, minVal = INT_MAX, maxVal = INT_MIN;
        for (int val : salary) {
            sumVal += val;
            minVal = std::min(minVal, val);
            maxVal = std::max(maxVal, val);
        }

        return static_cast<double>(sumVal - minVal - maxVal) / (salary.size() - 2);
    }
};
