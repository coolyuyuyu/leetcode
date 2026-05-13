class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        std::function<int(int, int, int)> encode = [](int x, int y, int z) {
            return 49 * x + 7 * y + z;
        };

        int dst = encode(target[0], target[1], target[2]);

        unordered_set<int> seen;
        vector<tuple<int, int, int>> pnts;
        for (const auto& p : points) {
            int x = p[0], y = p[1], z = p[2];
            if (seen.insert(encode(x, y, z)).second) {
                pnts.emplace_back(x, y, z);
            }
        }

        for (int k = 0; true; ++k) {
            if (seen.find(dst) != seen.end()) {
                return k;
            }

            bool inserted = false;
            for (int i = 0, n = pnts.size(); i < n; ++i) {
                auto [x1, y1, z1] = pnts[i];
                for (int j = i + 1; j < n; ++j) {
                    auto [x2, y2, z2] = pnts[j];
                    int x3 = (x1 + x2) / 2;
                    int y3 = (y1 + y2) / 2;
                    int z3 = (z1 + z2) / 2;
                    if (seen.insert(encode(x3, y3, z3)).second) {
                        pnts.emplace_back(x3, y3, z3);
                        inserted = true;
                    }
                }
            }
            if (!inserted) {
                break;
            }
        }

        return -1;
    }
};
