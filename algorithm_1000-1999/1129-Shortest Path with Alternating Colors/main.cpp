class Solution {
public:
    vector<int> byBFS(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // color 0: red, color 1: blue

        bool visited[n][2];
        for (int i = 0; i < n; ++i) {
            visited[i][0] = visited[i][1] = false;
        }

        vector<int> next[n][2];
        for (const auto& edge : redEdges) {
            next[edge[0]][0].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            next[edge[0]][1].push_back(edge[1]);
        }

        int src = 0;
        vector<int> ret(n, -1);
        ret[src] = 0;

        queue<pair<int, int>> q;
        q.emplace(src, 0);
        q.emplace(src, 1);
        for (int dist = 1; !q.empty(); ++dist) {
            for (int x = q.size(); 0 < x--;) {
                auto [curNode, curColor] = q.front();
                q.pop();

                int nxtColor = curColor ? 0 : 1;
                for (int nxtNode : next[curNode][curColor]) {
                    if (visited[nxtNode][nxtColor]) { continue; }
                    visited[nxtNode][nxtColor] = true;

                    if (ret[nxtNode] == -1) {
                        ret[nxtNode] = dist;
                    }

                    q.emplace(nxtNode, nxtColor);
                }
            }
        }

        return ret;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        return byBFS(n, redEdges, blueEdges);
    }
};
