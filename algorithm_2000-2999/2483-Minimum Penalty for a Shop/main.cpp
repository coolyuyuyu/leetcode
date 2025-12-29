class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalN = std::count(customers.begin(), customers.end(), 'N');

        int ret = n, rhtN = 0, rhtY = 0, minPenalty = (totalN - rhtN) + rhtY;
        for (int i = n - 1; i >= 0; --i) {
            rhtN += customers[i] == 'N';
            rhtY += customers[i] == 'Y';
            int penalty = (totalN - rhtN) + rhtY;
            if (penalty <= minPenalty) {
                minPenalty = penalty;
                ret = i;
            }
        }

        return ret;
    }
};
