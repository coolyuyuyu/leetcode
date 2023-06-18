class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ret = 0;
        while (5 <= mainTank) {
            int usedFuel = mainTank / 5 * 5;
            mainTank -= usedFuel;

            ret += 10 * usedFuel;
        
            int filledFuel = std::min(usedFuel / 5, additionalTank);
            mainTank += filledFuel;
            additionalTank -= filledFuel;
        }
        ret += 10 * mainTank;

        return ret;
    }
};
