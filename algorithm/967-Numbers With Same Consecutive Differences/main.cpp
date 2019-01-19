class Solution {
public:
    void numsSameConsecDiff(int level, int threshold, int num, int diff, vector<int>& nums) {
        if (threshold <= level) {
            nums.emplace_back(num);
            return;
        }

        int digit = num % 10;

        if (diff != 0) {
            if (diff <= digit) {
                numsSameConsecDiff(level + 1, threshold, num * 10 + digit - diff, diff, nums);
            }
            if (digit + diff < 10) {
                numsSameConsecDiff(level + 1, threshold, num * 10 + digit + diff, diff, nums);
            }
        }
        else {
            numsSameConsecDiff(level + 1, threshold, num * 10 + digit, diff, nums);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }

        vector<int> nums;
        for (int num = 1; num < 10; ++num) {
            numsSameConsecDiff(1, N, num, K, nums);
        }
        return nums;
    }
};