class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> cnts(100001, 0);
        for (int num : nums) {
            if (num & 1) {
                continue;
            }

            ++cnts[num];
        }

        int minNum = -1, maxCnt = 0;
        for (int num : nums) {
            if (maxCnt < cnts[num]) {
                minNum = num;
                maxCnt = cnts[num];
            }
            else if (maxCnt == cnts[num]) {
                if (num < minNum) {
                    minNum = num;
                }
            }
        }

        return minNum;
    }
};
