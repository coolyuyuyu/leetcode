class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0, altitude = 0;
        for (int diff : gain) {
            altitude += diff;
            ret = std::max(ret, altitude);
        }

        return ret;
    }
};
