class Solution {
public:
    // greedy
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        size_t n = capacity.size();
        vector<int> vacant(n);
        for (size_t i = 0; i < n; ++i) {
            vacant[i] = capacity[i] - rocks[i];
        }
        std::sort(vacant.begin(), vacant.end());

        for (size_t i = 0; i < n; ++i) {
            if (additionalRocks < vacant[i]) {
                return i;
            }
            additionalRocks -= vacant[i];
        }

        return n;
    }
};
