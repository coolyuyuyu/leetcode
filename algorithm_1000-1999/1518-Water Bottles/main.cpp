class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = 0;
        int emptyBottle = 0;
        for  (int emptyBottle = 0; numBottles; emptyBottle %= numExchange) {
            ret += numBottles;

            emptyBottle += numBottles;
            numBottles = emptyBottle / numExchange;
        }

        return ret;
    }
};
