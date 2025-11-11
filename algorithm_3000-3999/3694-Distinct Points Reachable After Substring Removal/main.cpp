class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_map<char, pair<int, int>> dirs = {
            {'U', {0, 1}},
            {'D', {0, -1}},
            {'L', {-1, 0}},
            {'R', {1, 0}},
        };

        int xFinal = 0, yFinal = 0;
        for (char c : s) {
            const auto& [dx, dy] = dirs[c];
            xFinal += dx, yFinal += dy;
        }

        unordered_set<long long> points;
        for (int i = 0, n = s.size(), xSum = 0, ySum = 0; i < n; ++i) {
            const auto& [dx, dy] = dirs[s[i]];
            xSum += dx, ySum += dy;

            if (i + 1 >= k) {
                points.emplace(((0LL + xFinal - xSum) << 32) + yFinal - ySum);
            }

            if (i + 1 >= k) {
                const auto& [dx2, dy2] = dirs[s[i + 1 - k]];
                xSum -= dx2, ySum -= dy2;
            }
        }

        return points.size();
    }
};
