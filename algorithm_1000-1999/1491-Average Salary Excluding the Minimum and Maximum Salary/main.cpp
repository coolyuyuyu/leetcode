class Solution {
public:
    double average(vector<int>& salary) {
        int sumVal = 0, maxVal = INT_MIN, minVal = INT_MAX;
        for (int val : salary) {
            sumVal += val;
            maxVal = std::max(maxVal, val);
            minVal = std::min(minVal, val);
        }

        return static_cast<double>(sumVal - maxVal - minVal) / (salary.size() - 2);
    }
};
