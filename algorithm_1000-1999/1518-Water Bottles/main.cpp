class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = 0;
        for (int numEmpties = 0; numBottles; numEmpties = numEmpties % numExchange) {
            ret += numBottles;

            numEmpties += numBottles;
            numBottles = numEmpties / numExchange;
        }

        return ret;
    }
};
