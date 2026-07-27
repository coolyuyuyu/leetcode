class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0;
        for (int i = 0, altitude = 0; i < gain.size(); ++i) {
            altitude += gain[i];
            ret = std::max(ret, altitude);
        }

        return ret;
    }
};
