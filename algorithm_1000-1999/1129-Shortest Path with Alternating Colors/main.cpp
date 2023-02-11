class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> rNexts(n), bNexts(n);
        for (const auto& edge : redEdges) {
            rNexts[edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            bNexts[edge[0]].push_back(edge[1]);
        }

        vector<int> rDists(n, INT_MAX), bDists(n, INT_MAX);
        rDists[0] = bDists[0] = 0;

        enum class Color {
            R = 0,
            B = 1,
        };
        queue<pair<int, Color>> q({ {0, Color::R}, {0, Color::B} });
        for (int dist = 1; !q.empty(); ++dist) {
            for (size_t j = q.size(); 0 < j--;) {
                auto [node, color] = q.front();
                q.pop();

                auto& nexts = (color == Color::R ? rNexts : bNexts);
                auto& dists = (color == Color::R ? rDists : bDists);
                for (int next : nexts[node]) {
                    if (dist < dists[next]) {
                        dists[next] = dist;
                        q.emplace(next, (color == Color::R ? Color::B : Color::R));
                    }
                }
            }
        }

        vector<int> dists(n);
        for (int i = 0; i < n; ++i) {
            dists[i] = std::min(rDists[i], bDists[i]);
            if (dists[i] == INT_MAX) {
                dists[i] = -1;
            }
        }

        return dists;
    }
};
