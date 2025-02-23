class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // dpN[i]: the maximum number of consecutive 1's from num[0:i] and ending at i without flip
        // dpY[i]: the maximum number of consecutive 1's from num[0:i] and ending at i with flip

        int ret = 0;
        int dpN = 0, dpY = INT_MIN;
        for (int num : nums) {
            int tmpN = dpN, tmpY = dpY;
            if (num == 0) {
                dpN = 0;
                dpY = tmpN + 1;
            }
            else {
                dpN = tmpN + 1;
                dpY = std::max(tmpN + 1, tmpY + 1);
            }

            ret = std::max(ret, dpY);
        }

        return ret;
    }
};
