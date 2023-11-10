class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, pair<int, int>> neighbor;
        for (const auto& p : adjacentPairs) {
            if (neighbor.find(p[0]) == neighbor.end()) {
                neighbor[p[0]] = {p[1], INT_MIN};
            }
            else {
                neighbor[p[0]].second = p[1];
            }

            if (neighbor.find(p[1]) == neighbor.end()) {
                neighbor[p[1]] = {p[0], INT_MIN};

            }
            else {
                neighbor[p[1]].second = p[0];
            }
        }

        int src;
        for (const auto& [key, p] : neighbor) {
            if (p.second == INT_MIN) {
                src = key;
                break;
            }
        }

        vector<int> ret(neighbor.size());
        ret[0] = src, ret[1] = neighbor[src].first;
        for (int i = 2; i < ret.size(); ++i) {
            int pre = ret[i - 1];
            ret[i] = (neighbor[pre].first == ret[i - 2] ? neighbor[ret[i - 1]].second : neighbor[ret[i - 1]].first);
        }

        return ret;
    }
};
