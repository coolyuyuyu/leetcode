class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = 0;
        for (int numEmpties = 0; numBottles; numBottles = numEmpties / numExchange, numEmpties = numEmpties % numExchange) {
            ret += numBottles;

            numEmpties += numBottles;
            numBottles = 0;
        }

        return ret;
    }
};
