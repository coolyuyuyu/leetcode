class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int numFulls = numBottles, numEmpties = 0;

        int ret = 0;
        while (numFulls) {
            ret += numFulls;
            numEmpties += numFulls;
            numFulls = 0;

            while (numEmpties >= numExchange) {
                numEmpties -= numExchange;
                ++numExchange;
                ++numFulls;
            }
        }

        return ret;
    }
};
