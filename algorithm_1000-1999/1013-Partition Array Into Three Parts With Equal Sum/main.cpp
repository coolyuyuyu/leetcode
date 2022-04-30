class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        if ((sum % 3) != 0) {
            return false;
        }

        size_t numPart = 0;
        int curSum = 0;
        for (int num : arr) {
            curSum += num;
            if (curSum == (sum / 3)) {
                curSum = 0;
                if (3 <= ++numPart) {
                    return true;
                }
            }
        }

        return false;
    }
};
