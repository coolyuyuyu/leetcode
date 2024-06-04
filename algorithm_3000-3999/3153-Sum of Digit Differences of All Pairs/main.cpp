class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        // cnts[i][d]: the number of occurence of digit d on position i
        int cnts[10][10];
        for (int i = 0; i < 10; ++i) {
            for (int d = 0; d < 10; ++d) {
                cnts[i][d] = 0;
            }
        }
        for (int num : nums) {
            for (int i = 0; num; ++i, num /= 10) {
                ++cnts[i][num % 10];
            }
        }

        long long ret = 0;
        for (int i = 0; i < 10; ++i) {
            for (int d = 0; d < 10; ++d) {
                ret += cnts[i][d] * (n - cnts[i][d]);
            }
        }

        return ret / 2;
    }
};
