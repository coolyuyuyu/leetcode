class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        int ret = 0;

        unordered_map<char, int> lastPos;
        for (int i = 0; i < n; ++i) {
            for (char c : garbage[i]) {
                lastPos[c] = i;
            }
            ret += garbage[i].size();
        }

        std::partial_sum(travel.begin(), travel.end(), travel.begin());
        for (char c : "MPG") {
            ret += lastPos[c] == 0 ? 0 : travel[lastPos[c] - 1];
        }

        return ret;
    }
};
