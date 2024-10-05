class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int cnts[1001];
        std::fill(cnts, cnts + 1001, 0);
        for (int num : nums) {
            ++cnts[num];
        }

        for (int num = 1000; num >= 0; --num) {
            if (cnts[num] == 1) {
                return num;
            }
        }

        return -1;
    }
};
