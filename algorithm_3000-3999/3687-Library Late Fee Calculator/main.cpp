class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int ret = 0;
        for (int day : daysLate) {
            if (day == 1) { ret += 1; }
            else if (day <= 5) { ret += 2 * day; }
            else { ret += 3 * day; }
        }

        return ret;
    }
};
