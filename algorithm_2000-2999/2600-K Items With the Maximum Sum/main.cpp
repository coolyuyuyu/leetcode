class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ret = 0;

        int pickA = std::min(k, numOnes);
        ret += pickA;
        k -= pickA;

        int pickB = std::min(k, numZeros);
        k -= pickB;

        int pickC = std::min(k, numNegOnes);
        ret -= pickC;
        k -= pickC;

        return ret;
    }
};
