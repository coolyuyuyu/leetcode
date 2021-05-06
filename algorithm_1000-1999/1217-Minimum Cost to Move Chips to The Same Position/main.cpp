class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        for (int pos : position) {
            if ((pos % 2) == 1) {
                ++odd;
            }
        }
        int even = position.size() - odd;

        return min(odd, even);
    }
};
