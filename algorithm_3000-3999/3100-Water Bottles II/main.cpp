class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ret = 0;
        for (int numEmpties = 0; numBottles;) {
            ret += numBottles;
            numEmpties += numBottles;
            numBottles = 0;
            while (numExchange <= numEmpties) {
                numBottles += 1;
                numEmpties -= numExchange;
                numExchange += 1;
            }
        }

        return ret;
    }
};
