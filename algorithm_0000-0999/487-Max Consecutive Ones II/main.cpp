class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flipN = 0; // flipN[i]: the number of consecutive 1's ending at i without flip
        int flipY = 0; // flipY[i]: the number of consecutive 1's ending at i with flip
        int ret = 0;
        for (int num : nums) {
            int tmpFlipN = flipN, tmpflipY = flipY;
            if (num == 0) {
                flipN = 0;
                flipY = tmpFlipN + 1;
            }
            else {
                flipN = tmpFlipN + 1;
                flipY = tmpflipY + 1;
            }

            ret = std::max(ret, flipY);
        }

        return ret;
    }
};
