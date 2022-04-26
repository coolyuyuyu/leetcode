class Solution {
public:
    int countElements(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = INT_MIN, minCnt = 0, maxCnt = 0;
        for (int num : nums) {
            if (num < minNum) {
                minNum = num;
                minCnt = 1;
            }
            else if (num == minNum) {
                ++minCnt;
            }

            if (maxNum < num) {
                maxNum = num;
                maxCnt = 1;
            }
            else if (num == maxNum) {
                ++maxCnt;
            }
        }

        return minNum == maxNum ? 0 : (nums.size() - minCnt - maxCnt);
    }
};
