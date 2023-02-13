class Solution {
public:
    int countOdds(int low, int high) {
        auto countOddsLE = [](int num) -> int {
            return num / 2 + (0 < num && num % 2 ? 1 : 0);
        };

        return countOddsLE(high) - countOddsLE(low - 1);
    }
};
