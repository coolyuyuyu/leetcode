class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> graph[n];
        vector<int> in(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            ++in[v];
        }

        std::function<int(char color, vector<int>)> f = [&](char color, vector<int> in) {
            int cnts[n]; std::fill(cnts, cnts + n, 0);
            queue<int> q;
            for (int v = 0; v < n; ++v) {
                if (in[v] == 0) {
                    cnts[v] = (colors[v] == color ? 1 : 0);
                    q.push(v);
                }
            }

            int visited = 0;
            for (; !q.empty(); ++visited) {
                auto cur = q.front();
                q.pop();

                for (int nxt : graph[cur]) {
                    cnts[nxt] = std::max(cnts[nxt], cnts[cur] + (colors[nxt] == color ? 1 : 0));
                    if (--in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }

            return visited == n ? *std::max_element(cnts, cnts + n) : -1;
        };

        int ret = 0;
        for (char color : unordered_set<char>(colors.begin(), colors.end())) {
            int val = f(color, in);
            if (val == -1) {
               return -1;
            }
            ret = std::max(ret, val);
        }

        return ret;
    }
};
