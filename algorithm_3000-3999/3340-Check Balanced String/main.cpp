class Solution {
public:
    bool isBalanced(string num) {
        int eSum = 0, oSum = 0;
        for (int i = 0; i < num.size(); ++i) {
            ((i & 1) ? oSum : eSum) += num[i] - '0';
        }

        return eSum == oSum;
    }
};
