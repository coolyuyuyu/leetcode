class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0;
        for (int i = 0, sum = 0; i < batteryPercentages.size(); ++i) {
            batteryPercentages[i] += sum;
            if (batteryPercentages[i] > 0) {
                ++ret;
                sum -= 1;
            }
        }

        return ret;
    }
};
