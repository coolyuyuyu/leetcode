class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ret = 0;
        for (int hour : hours) {
            if (target <= hour) {
                ++ret;
            }
        }

        return ret;
    }
};
