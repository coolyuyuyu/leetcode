class Solution {
public:
    // greedy
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int index = 0;
        for (int avail = 0, i = 0; i < gas.size(); ++i) {
            avail += gas[i];
            avail -= cost[i];
            if (avail < 0) {
                index = i + 1;
                avail = 0;
            }
        }

        return index;
    }
};
