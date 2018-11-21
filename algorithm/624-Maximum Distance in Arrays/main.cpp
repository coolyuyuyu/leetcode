class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;
        int minVal = arrays.front().front();
        int maxVal = arrays.front().back();
        for (size_t i = 1; i < arrays.size(); ++i) {
            const vector<int>& vals = arrays[i];
            maxDist = max(maxDist, max(vals.back() - minVal, maxVal - vals.front()));
            minVal = min(minVal, vals.front());
            maxVal = max(maxVal, vals.back());
        }

        return maxDist;

    }
};