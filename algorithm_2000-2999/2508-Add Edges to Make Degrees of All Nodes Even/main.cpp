class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> neighbors(n + 1);
        for (const auto& edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        auto disconnected = [&](int i, int j) {
            return neighbors[i].find(j) == neighbors[i].end();
        };

        vector<int> odds;
        for (int i = 1; i <= n; ++i) {
            if ((neighbors[i].size() % 2) == 1) {
                odds.push_back(i);
            }
        }

        if (odds.size() == 0) {
            return true;
        }
        else if (odds.size() == 2) {
            int a = odds[0], b = odds[1];
            if (disconnected(a, b)) {
                return true;
            }

            for (int i = 1; i <= n; ++i) {
                if (disconnected(a, i) && disconnected(b, i)) {
                    return true;
                }
            }
        }
        else if (odds.size() == 4) {
            int a = odds[0], b = odds[1], c = odds[2], d = odds[3];
            if ((disconnected(a, b) && disconnected(c, d)) ||
                (disconnected(a, c) && disconnected(b, d)) ||
                (disconnected(a, d) && disconnected(b, c))) {
                return true;
            }
        }

        return false;
    }
};
