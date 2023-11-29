class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // flipN[i]: the maximum number of consecutive 1's ending at i without flip
        // flipN[i]: the maximum number of consecutive 1's ending at i with one flip
        int flipN = 0;
        int flipY = INT_MIN;

        int ret = 0;
        for (int num : nums) {
            int tmpN = flipN, tmpY = flipY;
            if (num == 1) {
                flipN = tmpN + 1;
                flipY = std::max(tmpN + 1, tmpY + 1);
            }
            else {
                flipN = 0;
                flipY = tmpN + 1;
            }

            ret = std::max(ret, flipY);
        }

        return ret;
    }
};
